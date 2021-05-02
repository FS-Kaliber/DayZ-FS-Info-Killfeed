modded class PluginAdminLog extends PluginBase			
{
	private CarScript							m_CarScript;
	private EntityAI							m_Human;
	bool m_Headshootfeed;
	
  	void SendMessageToWorld(PlayerBase player, string message) {
		Param1<string> param = new Param1<string>( message );
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, param, true, NULL);
	}
	
	static string KillfeedGetDate()
	{
		int year, month, day;		
		GetYearMonthDay(year, month, day);		
		string returned_message = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(2);
		return returned_message;
	}

	static string KillfeedGetTime()
	{
		int hour, minute, second;				
		GetHourMinuteSecond(hour, minute, second);
		string returned_message = hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
		return returned_message;
	}

	static string KillfeedGetDateTime()
	{
		int year, month, day, hour, minute, second;		
		GetYearMonthDay(year, month, day);		
		GetHourMinuteSecond(hour, minute, second);
		string returned_message = KillfeedGetDate() + " " + KillfeedGetTime();
		return returned_message;
	}

	void LogKillfeedFile(string input)
	{
		string log_date_time = KillfeedGetDateTime();
		string formated = "[" + log_date_time + "] " + input;

		FileHandle file = OpenFile("$profile:KillfeedLogs.txt", FileMode.APPEND);
		if (file != 0)
		{
			FPrintln(file, formated);
			CloseFile(file);
		}
	}

    void LogKillfeed(string input)
    {
        LogKillfeedChat(input);
		LogKillfeedFile(input);
    }

	void LogKillfeedChat(string message)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		foreach( auto player : players  )
		{
			Param1<string> m_MessageParam = new Param1<string>(message);
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
		}
	}
	
	
	override string GetPlayerPrefix( PlayerBase player, PlayerIdentity identity )  // player name + id + position prefix for log prints
	{	
			
		if ( !identity ) 	// return partial message even if it fails to fetch identity 
		{
			return "Player Unknown";
		}
		
		m_PlayerName = identity.GetName();
		
		
		if ( !player.IsAlive() )
		{
		 	m_PlayerName = m_PlayerName + " (DEAD)"; 
		}
		
		return m_PlayerName;
	}

    
	override void BleedingOut( PlayerBase player ) 
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );

				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_BLOOD",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_BLOOD"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_BLOOD");	
						}	
	}

	override void Suicide( PlayerBase player ) 
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
		
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_KILLSELF",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_KILLSELF"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_KILLSELF");	
						}	

	}

    override void PlayerHitBy( TotalDamageResult damageResult, int damageType, PlayerBase player, EntityAI source, int component, string dmgZone, string ammo ) 
	{
		if ( player && source )		
		{
			m_PlayerPrefix = this.GetPlayerPrefix( player , player.GetIdentity() );
			m_HitMessage = this.GetHitMessage( damageResult, component, dmgZone, ammo );
			
			switch ( damageType )
			{
				case DT_CLOSE_COMBAT:	
				
					if ( m_HitFilter != 1 && ( source.IsZombie() || source.IsAnimal() ) )  
					{
						m_DisplayName = source.GetDisplayName();
												
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_DisplayName + m_HitMessage );	
					}			
					else if ( source.IsPlayer() )				
					{
						m_Source = PlayerBase.Cast( source );
						m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
					
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + m_HitMessage );
					}
					else if ( source.IsMeleeWeapon() )			
					{				
						m_ItemInHands = source.GetDisplayName();		
						m_Source = PlayerBase.Cast( source.GetHierarchyParent() );
						m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
					if ( dmgZone == "Head" ) 
					{    
					m_Headshootfeed = true;
					} else {
					m_Headshootfeed = false;
					}
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + m_HitMessage + " with " + m_ItemInHands );				
					}
					else
					{
						m_DisplayName = source.GetType();
					
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_DisplayName + m_HitMessage );					
					} 
					break;
				
				case DT_FIRE_ARM:	
				
					if ( source.IsWeapon() )
					{
						m_ItemInHands = source.GetDisplayName();				
						m_Source = PlayerBase.Cast( source.GetHierarchyParent() );
						m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
						m_Distance = vector.Distance( player.GetPosition(), m_Source.GetPosition() );
					if ( dmgZone == "Head" ) 
					{    
					m_Headshootfeed = true;
					} else {
					m_Headshootfeed = false;
					}
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + m_HitMessage + " with " + m_ItemInHands + " from " + m_Distance + " meters ");
					}
					else 
					{
						m_DisplayName = source.GetType();
					
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_DisplayName + m_HitMessage );			
					}
					break;
				
				case DT_EXPLOSION:		
                    if (!player.IsAlive())
                    {
                        //LogKillfeed( m_PlayerPrefix + " died from explosion" );
                    }
					break;
				case DT_CUSTOM:			
								
					if ( ammo == "FallDamage" )			
					{
                        if (!player.IsAlive())
                        {
							
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_FALL",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_FALL"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_FALL");	
						}

                        }
					}
						
					
					if ( ammo == "BearTrap" || source.GetType() == "BearTrap" )			
					{
                        if (!player.IsAlive())
                        {    
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_BEARTRAP",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_BEARTRAP"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_BEARTRAP");	
						}
						
                        }
					}					
					else if ( source.GetType() == "AreaDamageBase" )  
					{
						EntityAI parent = EntityAI.Cast( source );
						if ( parent )
						{
							//LogKillfeedChat( m_PlayerPrefix + " hit by " + parent.GetType() + " with " + ammo );	
						}
					}
					else
					{
						m_DisplayName = source.GetType();
										
						//LogKillfeedChat( m_PlayerPrefix + " hit by " + m_DisplayName + " with " + ammo );
					}
					break;
											
				default:
				
					//LogKillfeed("DEBUG: PlayerHitBy() unknown damageType: " + ammo );
					break;
			}
		}
	}
	
		override void UnconStart( PlayerBase player )	//  PlayerBase.c  
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
		
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_HELP",m_PlayerPrefix+ " #DENIK_UNCON",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_HELP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_UNCON"), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_HELP" +m_PlayerPrefix+ " #DENIK_UNCON");	
						}		
		
	}

    override void PlayerKilled( PlayerBase player, Object source ) 
	{
		
		if ( player && source )
		{
			m_PlayerPrefix = this.GetPlayerPrefix( player , player.GetIdentity() );
			
			if( player == source )	
			{
				m_StatWater = player.GetStatWater();
				m_StatEnergy = player.GetStatEnergy();
				m_BleedMgr = player.GetBleedingManagerServer();
				m_Source = PlayerBase.Cast( EntityAI.Cast( source ).GetHierarchyParent() );
                if (m_StatWater.Get() == 0)
				{
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_DEH",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_DEH"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_DEH");	
						}
						
                }
                else if (m_StatEnergy.Get() == 0)
				{
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_STARVED",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_STARVED"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_STARVED");	
						}					

                }
				else
				{
					//LogKillfeed(m_PlayerPrefix + " got damage from " + source.GetType());
					// LogKillfeed( m_PlayerPrefix + " killed himself" );
				}
			}
			else if ( source.IsWeapon() || source.IsMeleeWeapon() ) 
			{				
				m_Source = PlayerBase.Cast( EntityAI.Cast( source ).GetHierarchyParent() );
				m_PlayerPrefix2 = "";
				if(m_Source)
				{
					m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
				}

				if (player && m_Source)
				{
					m_Distance = Math.Round(vector.Distance( player.GetPosition(), m_Source.GetPosition() ));
				}

				if ( source.IsMeleeWeapon() )
				{	
						
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_KILLED " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF

						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_KILLED " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_KILLED " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!");	
						}						
					
				} 
				else
				{
					
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_KILLED " + m_PlayerPrefix2 + " #DENIK_WIHT " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF						
						if (m_Headshootfeed)
						{
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("<†>Headshoot<†>!!!"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_KILLED " + m_PlayerPrefix2 + " #DENIK_WIHT " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!"), "DENIK/gui/images/head.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);	
						}else{
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_KILLED " + m_PlayerPrefix2 + " #DENIK_WIHT " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_KILLED " + m_PlayerPrefix2 + " #DENIK_WIHT " + source.GetDisplayName() + " #DENIK_FROM " + m_Distance + "m!");	
						}	
						
				
			}	
			}
			else					
			{
                if (source.IsInherited(CarScript))
			    {
				
				m_CarScript = CarScript.Cast(source);
				Human driver = Human.Cast(m_CarScript.CrewMember(0));
				PlayerBase m_driver = PlayerBase.Cast(driver);
				
				if (m_driver)
				{
						if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_CAR",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
						if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF	
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_CAR"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
						if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_CAR");	
						}	
				    }
			    }				

                if (source.IsInherited(DayZInfected))
				{
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_ZOMBIE",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_ZOMBIE"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_ZOMBIE");	
						}				
				}
				
				

				if (source.IsInherited(LandMineTrap))
				{
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_EXP",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_EXP"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_EXP");	
						}
				}		

                //Bär	


				if (source.GetType() == "Animal_UrsusArctos")			
					{
 
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_BEAR",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_BEAR"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_BEAR");	
						}
						                      
					}
				
				
				if (source.GetType() == "Animal_CanisLupus_White" || source.GetType() == "Animal_CanisLupus_Grey")			
					{
 
				//Wolf	
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_WOLF",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_WOLF"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_WOLF");	
						}
						                      
					}
					
				//Tankstelle	
					
				if (source.GetType() == "Land_FuelStation_Feed")			
					{
 
					
				if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_RIP",m_PlayerPrefix+ " #DENIK_GAS",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						#endif
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
						{	
						//CF
						m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_RIP"), new ref StringLocaliser(m_PlayerPrefix+ " #DENIK_GAS"), "DENIK/gui/images/skull.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
						}
						
				if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
						{
						//Chat
						SendMessageToWorld(player,"#DENIK_RIP" +m_PlayerPrefix+ " #DENIK_GAS");	
						}
						                      
					}	
					


				//LogKillfeedChat(m_PlayerPrefix + " got damage Playerkill from " + source.GetType());
			}
		}
	  
	}
}

