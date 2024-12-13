#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** initializeInventory(int speciesCount) {
    char*** inventory = (char***)malloc(speciesCount * sizeof(char**));
    for (int i = 0; i < speciesCount; i++) {
        inventory[i] = NULL;
    }
    return inventory;
}

void addSupplies(char*** inventory, int speciesIndex, int supplyCount) {
    inventory[speciesIndex] = (char**)malloc(supplyCount * sizeof(char*));
    for (int i = 0; i < supplyCount; i++) {
        inventory[speciesIndex][i] = (char*)malloc(100 * sizeof(char));
        printf("Enter supply name for species %d, item %d: ", speciesIndex + 1, i + 1);
        scanf("%99s", inventory[speciesIndex][i]);
    }
}

void updateSupply(char*** inventory, int speciesIndex, int supplyIndex) {
    printf("Enter new name for supply at species %d, item %d: ", speciesIndex + 1, supplyIndex + 1);
    scanf("%99s", inventory[speciesIndex][supplyIndex]);
}

void removeSpecies(char*** inventory, int speciesIndex, int supplyCount) {
    for (int i = 0; i < supplyCount; i++) {
        free(inventory[speciesIndex][i]);
    }
    free(inventory[speciesIndex]);
    inventory[speciesIndex] = NULL;
}

void displayInventory(char*** inventory, int speciesCount, int* supplyCounts, char speciesNames[][100]) {
    for (int i = 0; i < speciesCount; i++) {
        if (inventory[i] != NULL) {
            printf("Species: %s supplies:\n", speciesNames[i]);
            for (int j = 0; j < supplyCounts[i]; j++) {
                printf("  %s\n", inventory[i][j]);
            }
        } else {
            printf("Species: %s has been removed.\n", speciesNames[i]);
        }
    }
}

void freeInventory(char*** inventory, int speciesCount, int* supplyCounts) {
    for (int i = 0; i < speciesCount; i++) {
        if (inventory[i] != NULL) {
            for (int j = 0; j < supplyCounts[i]; j++) {
                free(inventory[i][j]);
            }
            free(inventory[i]);
        }
    }
    free(inventory);
}

int main() {
    int speciesCount;
    printf("Enter number of species: ");
    scanf("%d", &speciesCount);

    char speciesNames[speciesCount][100];
    for (int i = 0; i < speciesCount; i++) {
        printf("Enter name of species %d: ", i + 1);
        scanf("%99s", speciesNames[i]);
    }

    char*** inventory = initializeInventory(speciesCount);
    int* supplyCounts = (int*)malloc(speciesCount * sizeof(int));

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int speciesIndex;
                printf("Enter species index (1 to %d) to add supplies: ", speciesCount);
                scanf("%d", &speciesIndex);
                speciesIndex--;

                printf("Enter number of supplies for species %s: ", speciesNames[speciesIndex]);
                scanf("%d", &supplyCounts[speciesIndex]);

                addSupplies(inventory, speciesIndex, supplyCounts[speciesIndex]);
                break;
            }

            case 2: {
                int speciesIndex, supplyIndex;
                printf("Enter species index (1 to %d) to update supply: ", speciesCount);
                scanf("%d", &speciesIndex);
                speciesIndex--;

                printf("Enter supply index (1 to %d) to update: ", supplyCounts[speciesIndex]);
                scanf("%d", &supplyIndex);
                supplyIndex--;

                updateSupply(inventory, speciesIndex, supplyIndex);
                break;
            }

            case 3: {
                int speciesIndex;
                printf("Enter species index (1 to %d) to remove: ", speciesCount);
                scanf("%d", &speciesIndex);
                speciesIndex--;

                removeSpecies(inventory, speciesIndex, supplyCounts[speciesIndex]);
                supplyCounts[speciesIndex] = 0;
                break;
            }

            case 4:
                displayInventory(inventory, speciesCount, supplyCounts, speciesNames);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeInventory(inventory, speciesCount, supplyCounts);
    free(supplyCounts);

    return 0;
}
