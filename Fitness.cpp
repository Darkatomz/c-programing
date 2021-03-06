#include"Fitness.h"



float Fitness::CalculateMacroRatio(float calories,float carbperc,float fatperc,float protienperc) {
	float carbformula{ carbperc / 100.0f }; float fatformula{ fatperc / 100.0f }; float proteinformula{ protienperc / 100.0f };
	//Calories from each macros
	kcal = calories;
	kcalcarbs = (calories * carbformula);
	kcalfat = (calories * fatformula);
	kcalprotein = (calories * proteinformula);
	//Now for the required grams needed for each macro
	//carbs 4 calories per gram
	//protien 4 calories per gram
	//fat 9 calories per gram
	carbs = kcalcarbs / 4;
	fat = kcalfat / 9;
	protien = kcalprotein / 4;
	return 1.0f;
	 
}
//Calculates how many kcal you need also your bodyweight is converted into pounds from kg

float Fitness::DetermaineHowManyKcalRequired(float bodyweight,Fitness::ActivityLevels activitylevel,std::string unitmeasurement) {
	if (unitmeasurement == "lbs" || unitmeasurement == "LBS") {
		kcal = bodyweight * activitylevel;
		return kcal;
	}
	else if (unitmeasurement == "kg" || unitmeasurement == "KG") {
		BodyWeightInKG = bodyweight * 2.20462f;
		kcal = BodyWeightInKG * activitylevel;
		return kcal;
	}

}

float Fitness::ChangeBodyWeight(Fitness::ChangeWeight Option,Fitness::ChangeMass Speed) {
	if (Option == LooseWeight) {
		if (Speed == Slow) {
			deficitkcal = kcal - _slow;
			return deficitkcal;
		}
		else if (Speed == Normal) {
			deficitkcal = kcal - _normal;
			return deficitkcal;
		}
		else if (Speed == Fast) {
			deficitkcal = kcal - _fast;
			return deficitkcal;
		}
		else if (Speed == ReallyFast) {
			deficitkcal = kcal - _reallyfast;
			return deficitkcal;
		}
	}

}

std::string Fitness::MeasureMentUnitConverter(std::string Measurementuni) {
	if (Measurementuni == "a" || Measurementuni == "A") {
		return "lbs";
	}
	else if (Measurementuni == "b" || Measurementuni == "B") {
		return "kg";
	}
	
}

void Fitness::Start() {
	std::cout << "\t\t\t\tFitness pro get fit get learn\n";
	std::cout << "[a]: Workout-out how many calories you need?\n";
	std::cout << "[b]: Workout-out how many calories you need and macros?\n";
	std::cout << "[c]: Workout-out how many macros you need?\n";
	std::cout << ">>>";
	std::cin >> UserOption;
	float Bodyweight_{};
	std::cout << "Please enter your bodyweight in either KG or lbs\n";
	std::cout << ">>>";
	std::cin >> Bodyweight_;
	std::cout << "[a]: Would you like your measurement in pounds(lbs)?\n";
	std::cout << "[b]: Would you like your measurement in kilograms(kg)?\n";
	std::cout << ">>>";
	std::string Measurementunit{};
	std::cin >> Measurementunit;
	switch (UserOption) {
	case'a':
		StartPromt1();
		char actvitylevelinput_;
		std::cout << ">>>";
		std::cin >> actvitylevelinput_;
		std::cout << "You need " << DetermaineHowManyKcalRequired(Bodyweight_, ConvertActivityLevelToOptions(actvitylevelinput_), MeasureMentUnitConverter(Measurementunit)) << " calories to maintain your bodyweight\n";
		break;
	case'b':
		StartPromt1();
		std::cout << ">>>";
		std::cin >> actvitylevelinput_;
		float* temp = new float[3];
		temp = StoreMacroPercentages();
		CalculateMacroRatio(DetermaineHowManyKcalRequired(Bodyweight_, ConvertActivityLevelToOptions(actvitylevelinput_), MeasureMentUnitConverter(Measurementunit)), temp[0], temp[1], temp[2]);
		DisplayInfo();
		delete[] temp;
		break;	
	};
	


}

float* Fitness::StoreMacroPercentages() {
	float* macropercent = new float[3];
	std::cout << "Enter Ratio you would like for your carbs?:";
	float carbper{}, fatper{}, protienper{};
	std::cin >> carbper;
	std::cout << "Enter Ratio you would like for your fats?:";
	std::cin >> fatper;
	std::cout << "Enter Ratio you would like for your protien?:";
	std::cin >> protienper;
	macropercent[0] = carbper;
	macropercent[1] = fatper;
	macropercent[2] = protienper;
	//didnt deallocate memory
	return macropercent;
}

void Fitness::StartPromt1() {
	std::cout << "Please enter your activity level from\n";
	std::cout << "[a]:Do nothing in the day? \n";
	std::cout << "[b]:Ocassionally move around? \n";
	std::cout << "[c]:A few activities in the day(somewhat active)? \n";
	std::cout << "[d]:Very active throughout the day? \n";
}

Fitness::ActivityLevels Fitness::ConvertActivityLevelToOptions(char optionforactivity) {
	if (optionforactivity == 'a') {
		return DoNothing;
	}
	else if (optionforactivity == 'b') {
		return OcassionalyMoveAround;
	}
	else if (optionforactivity == 'c') {
		return AfewActivities;
	}
	else if(optionforactivity == 'd') {
		return VeryActive;
	}
	return DoNothing;
}



std::string Fitness::MeasurementYouWant() {
	std::cout << "\t\t\t\tWhat measurement would you like?\n";
	std::cout << "[a]: Pounds(lbs)\n";
	std::cout << "[b]: Kilograms(kg)\n";
	char measurementyouwant;
	std::cin >> measurementyouwant;
	if (measurementyouwant == 'a' || measurementyouwant == 'A') {
		return "kg";
	}
	else if (measurementyouwant == 'b' || measurementyouwant == 'B') {
		return "lbs";
	}
}

void Fitness::DisplayInfo() {
	std::cout << "\t\tCalories\n";
	std::cout << "Calories required for maintanence: " << kcal << "\n";
	std::cout << "Calories from carbs: " << kcalcarbs << "\n";
	std::cout << "Calories from fat: " <<kcalfat << "\n";
	std::cout << "Calories from protein: " << kcalprotein << "\n";
	std::cout << "\n\nMacros\n";
	std::cout << "Carbs: " << carbs << "g\n";
	std::cout << "Fat: " << fat << "g\n";
	std::cout << "Protien: " << protien << "g\n";

	
}
