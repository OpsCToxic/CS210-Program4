/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Nov 2022
 */


 /* Single Programmer Affidavit
I the undersigned promise that the submitted assignment is my own work. While I was 
free to discuss ideas with others, the work contained is my own. I recognize that 
should this not be the case; I will be subject to penalties as outlined in the course 
syllabus. 
Name: Cameron Cobb
Red ID: 826504686
*/
#include "connectedcities.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void asserts(bool didPass, string message) {
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    
    // Begin Testing
    // A few sample testing code are provided below  
    
    /* Construct a graph for testing
        *    SD ---> DL <--------         
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */

    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};

    vector<pair<string, string>> trainRoutes;

    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("SJ", "SK");

    trainRoutes.emplace_back("IV", "DL");
    
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");

    vector<CityNode> cities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1, trainRoutes);

     //cities returned from the above call are sorted according to 
    //the ascending order of the city names and 
    //the descending order of the size of reachableCities starting from those cities
    
    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities"); 
    
    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");
    
    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");
    
    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities");
    
    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from city JL can reach 4 cities");
    
    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from city BV can reach 3 cities");
        
    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");

    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from city OD can reach 3 cities");

    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from city BU can reach 1 city"); 

    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding required for assignment 4
    
    vector<string> cities_2 {"SC"};
    vector<pair<string, string>> trainRoutes1;
    vector<CityNode> cities2 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2, trainRoutes1);
    asserts(cities2.at(0).getCity() == "SC", "First city should be SC");
    asserts(cities2.at(0).getReachableCities().size() == 1, "Train starting from city SC can reach 1 city"); 

    vector<string> cities_3 {};
    vector<pair<string, string>> trainRoutes2;
    vector<CityNode> cities3 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3, trainRoutes2);
    asserts(cities3.empty(), "No cities are present");

    vector<string> cities_4 {"NY", "BF"};
    vector<pair<string, string>> trainRoutes3;
    trainRoutes3.emplace_back("NY", "BF");
    vector<CityNode> cities4 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_4, trainRoutes3);
    asserts(cities4.at(0).getCity() == "NY", "First city should be NY");
    asserts(cities4.at(0).getReachableCities().size() == 2, "Train starting from city NY can reach 2 cities");
    asserts(cities4.at(1).getCity() == "BF", "Second city should be BF");
    asserts(cities4.at(1).getReachableCities().size() == 1, "Train starting from city BF can reach 1 city"); 

    vector<string> cities_5 {"SC", "IR", "SA", "AH", "MM", "CB", "YM", "LA", "LB", "BF"};
    vector<pair<string, string>> trainRoutes4;
    trainRoutes4.emplace_back("CB", "SC");
    trainRoutes4.emplace_back("SC", "IR");
    trainRoutes4.emplace_back("SC", "AH");
    trainRoutes4.emplace_back("AH", "LA");
    trainRoutes4.emplace_back("LB", "LA");
    trainRoutes4.emplace_back("IR", "LB");
    trainRoutes4.emplace_back("LB", "LA");
    trainRoutes4.emplace_back("LA", "BF");
    trainRoutes4.emplace_back("BF", "MM");
    trainRoutes4.emplace_back("MM", "YM");
    trainRoutes4.emplace_back("YM", "MM");
    vector<CityNode> cities5 = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_5, trainRoutes4);
    
    asserts(cities5.at(0).getCity() == "CB", "First city should be CB");
    asserts(cities5.at(0).getReachableCities().size() == 9, "Train starting from city CB can reach 9 cities");
    asserts(cities5.at(1).getCity() == "SC", "Second city should be SC");
    asserts(cities5.at(1).getReachableCities().size() == 8, "Train starting from city SC can reach 8 cities");
    asserts(cities5.at(2).getCity() == "IR", "Third city should be IR");
    asserts(cities5.at(2).getReachableCities().size() == 6, "Train starting from city IR can reach 6 cities");
    asserts(cities5.at(3).getCity() == "AH", "Fourth city should be AH");
    asserts(cities5.at(3).getReachableCities().size() == 5, "Train starting from city AH can reach 5 cities");
    asserts(cities5.at(4).getCity() == "LB", "Fifth city should be LB");
    asserts(cities5.at(4).getReachableCities().size() == 5, "Train starting from city LB can reach 5 cities");
    asserts(cities5.at(5).getCity() == "LA", "Sixth city should be LA");
    asserts(cities5.at(5).getReachableCities().size() == 4, "Train starting from city LA can reach 4 cities");
    asserts(cities5.at(6).getCity() == "BF", "Seventh city should be BF");
    asserts(cities5.at(6).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");
    asserts(cities5.at(7).getCity() == "MM", "Eighth city should be MM");
    asserts(cities5.at(7).getReachableCities().size() == 2, "Train starting from city MM can reach 2 cities");
    asserts(cities5.at(8).getCity() == "YM", "Ninth city should be YM");
    asserts(cities5.at(8).getReachableCities().size() == 2, "Train starting from city YM can reach 2 cities");
    asserts(cities5.at(9).getCity() == "SA", "Tenth city should be SA");
    asserts(cities5.at(9).getReachableCities().size() == 1, "Train starting from city SA can reach 1 city");
    
    

    // IMPORTANT: You should construct at least one different city graph similar to the one above
    //
    // Also make sure to construct graphs for testing the edge cases, 
    // such as empty graph (NO node), one node graph, two nodes graph, etc.

    cout << endl << "All test cases passed!" << endl;

    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}