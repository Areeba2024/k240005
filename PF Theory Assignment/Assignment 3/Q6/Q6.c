#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
    char date[20];
} Weather;

typedef struct Crop {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    Weather **weatherForecasts;
} Crop;

typedef struct Equipment {
    char equipmentName[50];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[100];
} Equipment;

typedef struct Sensor {
    float soilNutrients;
    float soilPH;
    int pestActivity;
    char timestamp[20];
} Sensor;

typedef struct Field {
    float latitude;
    float longitude;
    float soilHealth;
    float moistureLevel;
    Crop **crops;
    Equipment **equipment;
    Sensor **sensors;
} Field;

typedef struct RegionalHub {
    Field **fields;
    int numFields;
    float aggregateYieldPrediction;
    float resourceDistribution;
} RegionalHub;

int main() {
    RegionalHub *hub = (RegionalHub *)malloc(sizeof(RegionalHub));
    hub->numFields = 1;
    hub->fields = (Field **)malloc(sizeof(Field *) * hub->numFields);

    Field *field = (Field *)malloc(sizeof(Field));
    field->latitude = 36.7783;
    field->longitude = -119.4179;
    field->soilHealth = 85.0;
    field->moistureLevel = 40.0;

    field->crops = (Crop **)malloc(sizeof(Crop *));
    field->crops[0] = (Crop *)malloc(sizeof(Crop));
    strcpy(field->crops[0]->cropType, "Wheat");
    strcpy(field->crops[0]->growthStage, "Flowering");
    field->crops[0]->expectedYield = 2500.0;

    field->crops[0]->weatherForecasts = (Weather **)malloc(sizeof(Weather *));
    field->crops[0]->weatherForecasts[0] = (Weather *)malloc(sizeof(Weather));
    field->crops[0]->weatherForecasts[0]->temperature = 24.5;
    field->crops[0]->weatherForecasts[0]->rainfall = 10.0;
    field->crops[0]->weatherForecasts[0]->windSpeed = 12.5;

    hub->fields[0] = field;

    printf("Field at %.4f, %.4f\n", field->latitude, field->longitude);
    printf("Crop: %s, Growth Stage: %s, Expected Yield: %.2f kg\n", 
           field->crops[0]->cropType,
           field->crops[0]->growthStage, 
           field->crops[0]->expectedYield);
    printf("Weather Forecast: %.2f°C, %.2f mm rainfall, %.2f km/h wind\n", 
           field->crops[0]->weatherForecasts[0]->temperature, 
           field->crops[0]->weatherForecasts[0]->rainfall,
           field->crops[0]->weatherForecasts[0]->windSpeed);

    free(field->crops[0]->weatherForecasts[0]);
    free(field->crops[0]->weatherForecasts);
    free(field->crops[0]);
    free(field->crops);
    free(field);
    free(hub->fields);
    free(hub);

    return 0;
}
