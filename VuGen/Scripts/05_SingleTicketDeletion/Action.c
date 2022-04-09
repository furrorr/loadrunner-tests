Action()
{

	lr_start_transaction("05_SingleTicketDeletion");
	
	
	homePage();
	

	login();
	

	lr_start_transaction("Itinerary");
	
	web_reg_find("Text/IC=User wants the intineraries",
		LAST);
	
//	web_reg_save_param("FlightID",
//		"LB/IC=name=\"flightID\" value=\"",
//		"RB/IC=-",
//		"Ord=ALL",
//		LAST);
	
	web_reg_save_param("FlightID",
		"LB/IC=name=\"flightID\" value=\"",
		"RB/IC=\"",
		"Ord=ALL",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(5);

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

	lr_think_time(5);
	
	if (atoi(lr_eval_string("{FlightID_count}")) > 20){
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_1}",
		LAST);
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_2}",
		LAST);
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_3}",
		LAST);

	web_submit_form("itinerary.pl",
		"Snapshot=t19.inf",	                
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=3", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM,		
		LAST);
		
	}
	
	else if (atoi(lr_eval_string("{FlightID_count}")) > 10){
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_1}",
		LAST);
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_2}",
		LAST);

	web_submit_form("itinerary.pl",
		"Snapshot=t19.inf",	                
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM,		
		LAST);
		
	}
	
	else if (atoi(lr_eval_string("{FlightID_count}")) > 1){
		
		web_reg_find("Fail=Found",
		"Text/IC={FlightID_1}",
		LAST);

	web_submit_form("itinerary.pl",
		"Snapshot=t19.inf",	                
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM,		
		LAST);
		
	}
	
	lr_end_transaction("DeleteItinerary",LR_AUTO);
	
	
	logout();
	
	
	lr_end_transaction("05_SingleTicketDeletion",LR_AUTO);
	

	return 0;
}