modded class MissionServer extends MissionBase
{
		void MissionServer()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.RestartTimeInfo, 60000, true);	
	}
	
//Restart Info

		bool firstlogin;
		bool Finished;
		string localtime;
		
	static string RSGetDate()
	{
		int year, month, day;		
		GetYearMonthDay(year, month, day);		
		string returned_message = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(2);
		return returned_message;
	}

	static string RSGetTime()
	{
		int hour, minute, second;				
		GetHourMinuteSecond(hour, minute, second);
		string returned_message = hour.ToStringLen(2) + ":" + minute.ToStringLen(2);
		return returned_message;
	}

	static string RSGetDateTime()
	{
		int year, month, day, hour, minute, second;		
		GetYearMonthDay(year, month, day);		
		GetHourMinuteSecond(hour, minute, second);
		string returned_message = RSGetDate() + " " + RSGetTime();
		return returned_message;
	}

	void RestartTimeInfo()
	{
		localtime = RSGetTime();			
		int i = 0;		
		Finished = false;
		for (i = 0; i < g_Game.denik_Config.DENIKBASE.RestartTime.Count(); i++){
			
		if (!Finished)
		{
		////////////////////  0 UHR  /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "00")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "23:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "23:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "23:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "23:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "23:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "23:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}
		
		////////////////////   1 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "01")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "00:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "00:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "00:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "00:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "00:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "00:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}

		////////////////////   2 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "02")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "01:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "01:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "01:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "01:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "01:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "01:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}		

		////////////////////   3 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "03")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "02:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "02:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "02:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "02:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "02:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "02:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   4 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "04")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "03:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "03:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "03:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "03:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "03:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "03:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   5 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "05")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "04:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "04:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "04:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "04:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "04:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "04:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   6 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "06")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "05:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "05:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "05:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "05:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "05:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "05:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   7 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "07")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "06:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "06:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "06:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "06:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "06:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "06:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	
		
		////////////////////   8 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "08")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "07:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "07:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "07:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "07:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "07:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "07:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   9 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "09")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "08:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "08:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "08:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "08:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "08:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "08:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   10 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "10")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "09:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "09:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "09:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "09:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "09:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "09:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   11 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "11")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "10:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "10:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "10:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "10:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "10:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "10:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}		

		////////////////////   12 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "12")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "11:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "11:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "11:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "11:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "11:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "11:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}
		
		////////////////////   13 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "13")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "12:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "12:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "12:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "12:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "12:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "12:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   14 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "14")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "13:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "13:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "13:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "13:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "13:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "13:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	
		
		////////////////////   15 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "15")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "14:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "14:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "14:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "14:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "14:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "14:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   16 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "16")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "15:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "15:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "15:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "15:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "15:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "15:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   17 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "17")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "16:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "6:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "16:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "16:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "16:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "16:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   18 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "18")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "17:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "17:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "17:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "17:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "17:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "17:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   19 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "19")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "18:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "18:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "18:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "18:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "18:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "18:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}

		////////////////////   20 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "20")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "19:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "19:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "19:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "19:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "19:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "19:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   21 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "21")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "20:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "20:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "20:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "20:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "20:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "20:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}

		////////////////////   22 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "22")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "21:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "21:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "21:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "21:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "21:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "21:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}	

		////////////////////   23 UHR   /////////////////////////
		if (g_Game.denik_Config.DENIKBASE.RestartTime[i] == "23")
		{	
			if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
				{
			if (localtime == "22:45")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 15 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}	
			if (localtime == "22:55")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 5 Minuten!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}			
			if (localtime == "22:59")
				{					
					m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser("Server Restart in 1 Minute!!!" ), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),20,);
					Finished = true;
				}
				}
				
			if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
			#ifdef VPPNOTIFICATIONS
						{
			if (localtime == "22:45")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 15 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}	
			if (localtime == "22:55")
				{
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 5 Minuten!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
					Finished = true;
				}			
			if (localtime == "22:59")
				{	
					g_Game.SendMessage(true,NULL,"Server Info!","Server Restart in 1 Minute!!!",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
					Finished = true;
				}							
				}
				#endif
		}		
		
		}
	  }		
	}



	
	string 							m_PlayerName;
	string							m_Pid;
	vector 							m_Position; 
	string							playername;
	string 							m_PosArray[3];
	int 							m_DotIndex;
	
	
		string GetPlayerPrefix( PlayerBase player, PlayerIdentity identity )  // player name + id + position prefix for log prints
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
	
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);
		 
        string pname = identity.GetName();
		
		if (player) {
			
			if (g_Game.denik_Config.DENIKBASE.MessageInfo == 1){
					
					if (g_Game.denik_Config.DENIKBASE.MessageSystem == 3) // 1=TextChat 2=CF 3=VPPNotification
						{	
						//VPPNotification
						#ifdef VPPNOTIFICATIONS
						g_Game.SendMessage(true,NULL,"#DENIK_INFO",identity.GetName()+ " #DENIK_LOGIN",g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);
						
						
													
							if (g_Game.denik_Config.DENIKBASE.WillcomeMessageDisplay == 1 && firstlogin == false) {
							firstlogin = true;	
							g_Game.SendMessage(true,NULL,"Server Info!",pname+ g_Game.denik_Config.DENIKBASE.WillcomeMessage,g_Game.denik_Config.DENIKBASE.MessageTime,2,false,true,"",0,0);	
							}
							#endif
						}
						
						if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
							{	
							//CF
							
						    m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_INFO"), new ref StringLocaliser(identity.GetName()+ " #DENIK_LOGIN"), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
							
							
							if (g_Game.denik_Config.DENIKBASE.WillcomeMessageDisplay == 1 && firstlogin == false) {
							firstlogin = true;	
							m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("Server Info!"), new ref StringLocaliser(pname+ g_Game.denik_Config.DENIKBASE.WillcomeMessage), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),30,player.GetIdentity());	
							}
							
							}
							if(g_Game.denik_Config.DENIKBASE.MessageSystem == 1)
							{
							//Chat
							//SendMessageToWorld(player,identity.GetName()+ " #DENIK_LOGIN");	
							}	

			}
		}
	}


	override void InvokeOnDisconnect( PlayerBase player )
	{
		
		
		playername = this.GetPlayerPrefix( player , player.GetIdentity() );
							
			if(playername){				
							if (g_Game.denik_Config.DENIKBASE.MessageInfo == 1){

							if(g_Game.denik_Config.DENIKBASE.MessageSystem == 2)
							{	
							//CF
							m_DENIKNotificationSystem.CreateNotification(new ref StringLocaliser("#DENIK_INFO"), new ref StringLocaliser(playername+ " #DENIK_LOGOUT"), "DENIK/gui/images/info.paa", ARGB(255,0,100,200),g_Game.denik_Config.DENIKBASE.MessageTime);
							}
						}
					}
		super.InvokeOnDisconnect(player);			
		
	}






	
}