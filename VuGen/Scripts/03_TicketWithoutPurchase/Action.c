Action()
{

	lr_start_transaction("03_TicketWithoutPurchase");
	
	
	
	homePage();
	
	
	
	login();
	
	
	
	flights();
	
	

	lr_start_transaction("FlightTime");
	
	web_reg_find("Text/IC=from <B>{citiesDepart}</B> to <B>{citiesArrive}</B> on <B>{departDate}</B>",
		LAST);

	web_add_auto_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(5);
		
		web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);
		
		web_reg_save_param("returnFlight",
		"LB/IC=name=\"returnFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST); 

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={citiesDepart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={citiesArrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={placePref}", ENDITEM, 
		"Name=seatType", "Value={placeType}", ENDITEM, 
		"Name=findFlights.x", "Value=61", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("FlightTime",LR_AUTO);

	lr_think_time(5);
	
	
	
	
	lr_start_transaction("PaymentDetails");
	
	web_reg_find("Text/IC=Flight Reservation",
		LAST);
	
	lr_save_string(lr_paramarr_random("outboundFlight"), "boundFlight");
	
	lr_save_string(lr_paramarr_random("returnFlight"), "retFlight");

	web_submit_data("reservations.pl_2",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={boundFlight}", ENDITEM,
		"Name=returnFlight", "Value={retFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={placeType}", ENDITEM,
		"Name=seatPref", "Value={placePref}", ENDITEM,
		"Name=reserveFlights.x", "Value=46", ENDITEM,
		"Name=reserveFlights.y", "Value=8", ENDITEM,
		LAST);

	lr_end_transaction("PaymentDetails",LR_AUTO);

	lr_think_time(5);
	
	
	
	//logout();
	

	
	lr_end_transaction("03_TicketWithoutPurchase",LR_AUTO);
	
	

	return 0;
}