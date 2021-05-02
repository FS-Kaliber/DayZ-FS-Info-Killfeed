class DENIK_DENIKBASESettings : Managed{
	    int MessageSystem = 2;
		int MessageTime = 15;
		int MessageInfo = 1;
		int MessageKill = 1;
		int WillcomeMessageDisplay = 1;
		string WillcomeMessage = " welcome to our server!";
		ref TStringArray RestartTime =  { "00", "06", "12", "14", "18"};
		
		
	void DENIK_DENIKBASESettings() { }
}