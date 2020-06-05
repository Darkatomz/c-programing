#pragma once
#include<iostream>
#include<fstream>

class Fitness {

private:
	enum ChangeMass
		{
			Slow=1,Normal,Fast,ReallyFast
		};

	enum ActivityLevels
		{
		DoNothing = 14, OcassionalyMoveAround,AfewActivities,VeryActive
		};
	enum ChangeWeight {
		LooseWeight = 1, MaintainWeight,GainWeight
		};

	float CalculateMacroRatio(float kcal, float carbperc, float fatperc, float protienperc);
	float DetermaineHowManyKcalRequired(float bodyweight, ActivityLevels activitylevel, std::string unit);//Calculated how many kcal you need(for either kg or lbs)
	void DisplayInfo();
	float ChangeBodyWeight(ChangeWeight Option, ChangeMass Speed);
	std::string MeasurementYouWant();
	ActivityLevels ConvertActivityLevelToOptions(char optionforactivity);
	std::string MeasureMentUnitConverter(std::string Measurement);
	void StartPromt1();
	float* StoreMacroPercentages();
	const float _slow{ 200.0f }, _normal{ 300.0f }, _fast{ 350.0f }, _reallyfast{ 500.0f };
	float kcal{}, carbs{}, fat{}, protien{};
	std::string User{};
	float kcalcarbs{};
	float kcalfat{};
	float kcalprotein{};
	float BodyWeightInKG{};
	float deficitkcal{};
	float surpluskcal{};
	char UserOption{};

public:
	void Start();
	
};
