Action()
{

	lr_start_transaction("01_UserRegistration");
	
	
	
	homePage();
	

	
	lr_start_transaction("SignUp");
	
	web_reg_find("Text=First time registering?",
		LAST);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(5);

	web_url("login.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("SignUp",LR_AUTO);
	
	

	lr_start_transaction("Ñongratulation");
	
	web_reg_find("Text=User Information",
		LAST);

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	lr_think_time(5);

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={userLogin}", ENDITEM, 
		"Name=password", "Value={userPassword}", ENDITEM, 
		"Name=passwordConfirm", "Value={userPassword}", ENDITEM, 
		"Name=firstName", "Value={userFirstName}", ENDITEM, 
		"Name=lastName", "Value={userLastName}", ENDITEM, 
		"Name=address1", "Value={userAddress}", ENDITEM, 
		"Name=address2", "Value={userCity}", ENDITEM, 
		"Name=register.x", "Value=66", ENDITEM, 
		"Name=register.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("Ñongratulation",LR_AUTO);
	
	
	
	lr_start_transaction("PersonalAccount");
	
	web_reg_find("Text=User has returned to the home page",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(5);

	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("PersonalAccount",LR_AUTO);
	
	
	
	logout();
	

	
	lr_end_transaction("01_UserRegistration",LR_AUTO);
	
	
	
	return 0;
}