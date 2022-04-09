Action()
{

	lr_start_transaction("06_ViewingTickets");
	
	
	homePage();
	

	login();
	
	
	flights();
	

	lr_start_transaction("Itinerary");
	
	web_reg_find("Text/IC=User wants the intineraries",
		LAST);
	
	web_reg_save_param("FlightID",
		"LB/IC=name=\"flightID\" value=\"",
		"RB/IC=-",
		"Ord=ALL",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(5);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);
	
	
	lr_end_transaction("06_ViewingTickets",LR_AUTO);
	

	return 0;
}