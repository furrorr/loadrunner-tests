Action()
{

	lr_start_transaction("07_Login");
	
	
	homePage();
	

	login();
	

	lr_end_transaction("07_Login",LR_AUTO);
	

	return 0;
}