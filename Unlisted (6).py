vechile_type=input("Enter vechile type:")
hrs_parked=int(input("Enter no of hours:"))
if vechile_type=="Car":
    print("Car charges:",20*hrs_parked)
elif vechile_type=="Bike":
    print("Bike charges:",10*hrs_parked)
elif vechile_type=="Bus":
    print("Bus charges:",50*hrs_parked)
else:
    print("Invalid vechile type")