ref NotificationSystem m_DENIKNotificationSystem = new NotificationSystem();
modded class DayZGame extends CGame {

	autoptr ref DENIK_Config denik_Config;

	override void OnAfterCreate() {
        super.OnAfterCreate();
		if (IsServer()) {
			denik_Config = new DENIK_Config;
		}
		
	}

}