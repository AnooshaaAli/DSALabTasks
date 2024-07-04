#pragma once
#include<iostream>
#include<string>
using namespace std;

string recommendFriend(string Id, string* profiles, string interests[][3], int users) {
    int userIndex = -1;

    // Find the index of the user with the specified Id
    for (int i = 0; i < users; i++) {
        if (profiles[i] == Id) {
            userIndex = i;
            break;
        }
    }

    // Calculate the number of common interests with each user
    int maxCommonInterests = -1;
    string recommendedFriend;

    for (int i = 0; i < users; i++) {
        if (i != userIndex) {
            int commonInterests = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (interests[userIndex][j] == interests[i][k]) {
                        commonInterests++;
                        break; // No need to continue checking if an interest is already found
                    }
                }
            }
            if (commonInterests > maxCommonInterests) {
                maxCommonInterests = commonInterests;
                recommendedFriend = profiles[i];
            }
        }
    }

    return recommendedFriend;
}
