Action()
{

	lr_start_transaction("04_MultiplePassengerTicketPurchase");
	

	
	homePage();
	

	
	login();
	
	
	
	lr_start_transaction("Itinerary");
	
	web_reg_find("Text/IC=User wants the intineraries",
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(3);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("Itinerary",LR_AUTO);
	

	
	flights();
	
	

	lr_start_transaction("FlightTime");
	
	web_reg_find("Text/IC=from <B>{citiesDepart}</B> to <B>{citiesArrive}</B>",
		LAST);

	web_add_auto_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(3);
		
		web_reg_save_param("outboundFlight",
		"LB/IC=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={citiesDepart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={citiesArrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={NoOfPassengers}", ENDITEM, 
		"Name=seatPref", "Value={placePref}", ENDITEM, 
		"Name=seatType", "Value={placeType}", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("FlightTime",LR_AUTO);

	lr_think_time(4);
	
	

	lr_start_transaction("PaymentDetails");
	
	web_reg_find("Text/IC=Flight Reservation",
		LAST);
	
	web_reg_find("Text/IC=name=\"seatType\" value=\"{placeType}\"",
		LAST);
	
	web_reg_find("Text/IC=name=\"seatPref\" value=\"{placePref}\"",
		LAST);
	
	lr_save_string(lr_paramarr_random("outboundFlight"), "boundFlight");

	web_submit_data("reservations.pl_2",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={boundFlight}", ENDITEM,
		"Name=numPassengers", "Value={NoOfPassengers}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={placeType}", ENDITEM,
		"Name=seatPref", "Value={placePref}", ENDITEM,
		"Name=reserveFlights.x", "Value=65", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("PaymentDetails",LR_AUTO);

	lr_think_time(5);
	
	

	lr_start_transaction("Confirmation");
	
	web_reg_find("Text/IC=Thank you for booking through Web Tours",
		LAST);
	
	if (atoi(lr_eval_string("{NoOfPassengers}")) == 1){
		
		web_submit_data("reservations.pl_3",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={userFirstName}", ENDITEM,
		"Name=lastName", "Value={userLastName}", ENDITEM,
		"Name=address1", "Value={userAddress}", ENDITEM,
		"Name=address2", "Value={userCity}", ENDITEM,
		"Name=pass1", "Value={userPassengerNames_1}", ENDITEM,
		"Name=creditCard", "Value={userCreditCard}", ENDITEM,
		"Name=expDate", "Value={userExpDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={NoOfPassengers}", ENDITEM,
		"Name=seatType", "Value={placeType}", ENDITEM,
		"Name=seatPref", "Value={placePref}", ENDITEM,
		"Name=outboundFlight", "Value={boundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=58", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
		
	}
	
	else if (atoi(lr_eval_string("{NoOfPassengers}")) == 2){
		
		web_submit_data("reservations.pl_3",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={userFirstName}", ENDITEM,
		"Name=lastName", "Value={userLastName}", ENDITEM,
		"Name=address1", "Value={userAddress}", ENDITEM,
		"Name=address2", "Value={userCity}", ENDITEM,
		"Name=pass1", "Value={userPassengerNames_1}", ENDITEM,
		"Name=pass2", "Value={userPassengerNames_2}", ENDITEM,
		"Name=creditCard", "Value={userCreditCard}", ENDITEM,
		"Name=expDate", "Value={userExpDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={NoOfPassengers}", ENDITEM,
		"Name=seatType", "Value={placeType}", ENDITEM,
		"Name=seatPref", "Value={placePref}", ENDITEM,
		"Name=outboundFlight", "Value={boundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=58", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
		
	}
	
	else if (atoi(lr_eval_string("{NoOfPassengers}")) == 3){
		
		web_submit_data("reservations.pl_3",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={userFirstName}", ENDITEM,
		"Name=lastName", "Value={userLastName}", ENDITEM,
		"Name=address1", "Value={userAddress}", ENDITEM,
		"Name=address2", "Value={userCity}", ENDITEM,
		"Name=pass1", "Value={userPassengerNames_1}", ENDITEM,
		"Name=pass2", "Value={userPassengerNames_2}", ENDITEM,
		"Name=pass3", "Value={userPassengerNames_3}", ENDITEM,
		"Name=creditCard", "Value={userCreditCard}", ENDITEM,
		"Name=expDate", "Value={userExpDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={NoOfPassengers}", ENDITEM,
		"Name=seatType", "Value={placeType}", ENDITEM,
		"Name=seatPref", "Value={placePref}", ENDITEM,
		"Name=outboundFlight", "Value={boundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=58", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
		
	}

	lr_end_transaction("Confirmation",LR_AUTO);

	

	logout();
	
	
	
	lr_end_transaction("04_MultiplePassengerTicketPurchase",LR_AUTO);
	

	
 	return 0;
}