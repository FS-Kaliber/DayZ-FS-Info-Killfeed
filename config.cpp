class CfgPatches
{
	class DENIK
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class DENIK
	{
		dir="DENIK";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DayZ-Info-Killfeed";
		credits="=FS=Kaliber";
		author="=FS=Kaliber";
		authorID="0";
		version="1.5";
		extra=0;
		type="mod";
		inputs="";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"DENIK/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"DENIK/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"DENIK/Scripts/5_Mission"
				};
			};
		};
	};
};

