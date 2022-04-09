Action()
{

	lr_start_transaction("05_SingleTicketDeletion");

	lr_start_transaction("HomePage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1648740916; DOMAIN=127.0.0.1");

	web_add_cookie("MTUserInfo=firstName&Carlos&address2&Brooklyn&username&acrobat&hash&84&lastName&Watson%0A&address1&22%20Church%20Street&creditCard&&expDate&%0A; DOMAIN=127.0.0.1");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"99\", \"Google Chrome\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);

	lr_start_transaction("Login");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_submit_form("login.pl", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=username", "Value=sergey", ENDITEM, 
		"Name=password", "Value=pass", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("Itinerary");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(12);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);

	lr_start_transaction("DeleteItinerary");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(14);

	web_submit_form("itinerary.pl", 
		"Snapshot=t9.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		"Name=3", "Value=<OFF>", ENDITEM, 
		"Name=4", "Value=<OFF>", ENDITEM, 
		"Name=5", "Value=<OFF>", ENDITEM, 
		"Name=6", "Value=<OFF>", ENDITEM, 
		"Name=7", "Value=<OFF>", ENDITEM, 
		"Name=8", "Value=<OFF>", ENDITEM, 
		"Name=9", "Value=<OFF>", ENDITEM, 
		"Name=10", "Value=<OFF>", ENDITEM, 
		"Name=11", "Value=<OFF>", ENDITEM, 
		"Name=12", "Value=<OFF>", ENDITEM, 
		"Name=13", "Value=<OFF>", ENDITEM, 
		"Name=14", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("DeleteItinerary",LR_AUTO);

	lr_start_transaction("Logout");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(11);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t10.inf", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("05_SingleTicketDeletion",LR_AUTO);

	return 0;
}