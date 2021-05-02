class DENIK_Config : Managed {
	//__________________________________________________________________//
	//--------------------Config.JSON contents:-------------------------//
	// DENIKBASE settings section
	autoptr ref DENIK_DENIKBASESettings DENIKBASE;
    
	int version = 3;
	//___________________________________________________________________//

	void DENIK_Config() {
        Init();
        LoadFromDENIKJson();
	}

	void Init() {
		// Create mod folder in the server profile folder (if it doesn't exist yet).
		MakeDirectory(DENIK_CONFIG_FOLDER);
        DENIKBASE = new ref DENIK_DENIKBASESettings;

	}


	bool IsBroken() {}
	void LoadFromDENIKJson() {
		
		if (FileExist(DENIK_CONFIG_JSON))
		{
			// Load it
			JsonFileLoader<DENIK_Config>.JsonLoadFile(DENIK_CONFIG_JSON, this);
			// Check for new/missing settings
		}
		
		if (this.IsBroken()) {
			// Load defaults and rewrite/create the Json file with default values
			Print("The file 'DENIK_Config.json' is corrupted or doesn't exist, a new file is going to be created with default values.");
			LoadDefaultDENIKConfig();
		}
			// Save it (with updated & reformatted values)
			JsonFileLoader<DENIK_Config>.JsonSaveFile(DENIK_CONFIG_JSON, this);
		

	}

	void LoadDefaultDENIKConfig() {
		Init();
		JsonFileLoader<DENIK_Config>.JsonSaveFile(DENIK_CONFIG_JSON, this);
		
	}
}