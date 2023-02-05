#include "connectedcities.h"
#include <iostream>

 /* Single Programmer Affidavit
I the undersigned promise that the submitted assignment is my own work. While I was 
free to discuss ideas with others, the work contained is my own. I recognize that 
should this not be the case; I will be subject to penalties as outlined in the course 
syllabus. 
Name: Cameron Cobb
Red ID: 826504686
*/

/**
 * <p>
 * Part A 
 * ---------------------------------------------------------------------------------------
 * For each city in a city list, find the list of reachable cities starting from the city 
 * following the train routes, and sort the cities in the descending order based on the 
 * number of their reachable cities.  
 * 
 * Required specifications - 
 *
 * Given a list of cities, and a list of one-way train routes from one city to another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
 *    cities starting from the city following the train routes and store those reachable cities to 
 *    the CityNode's reachableCities collection. 
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.  
 *
 *    Note: The train route can go from the starting city and stop at several cities 
 *          before reaching the destination city, all cities including the starting city and 
 *          the destination city along the path would be counted as reachable cities from 
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the train can 
 *    reach the greatest number of destination cities following the given one-way routes. 
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
 *    all reachable cities from a starting city given the train routes, using an iterative 
 *    approach would result in a 30% penalty to your assignment 4 grade.  
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for hints.
 * 
 * Assumptions - 
 * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example, 
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
 *    Los Angeles (LA). 
 *
 * <p>
 * Part B
 * ---------------------------------------------------------------------------------------
 * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 * 
 * ---------------------------------------------------------------------------------------
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route represented 
 *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }   
 *                       refer to driver.cpp for more examples.  
 *
 * @return       A list of CityNode in the descending order based on the number of their 
 *               reachable cities following the train routes
 
* @see         
*/
vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(
                                    vector<string> cities, 
                                    vector<pair<string, string>> trainRoutes) {
                                        // Write your implementation here.
  // Follow the steps in the specification above to implement. 

  // You may want to implement each step in the above specification in 
  // a separate function.

  // Think what would be a good data structure to store the City Graph.
  // Each node/vertice represents a city and each has an adjacent list of cities
  // that can be reached directly from the city.
  // You can use a STL collection to store
  // the graph of city nodes, so that given a city code,
  // you can find the corresponding CityNode object instantaneously.
  // Think Which data structure would give you the best lookup ability
  // by using a key. 


  // Hint for DFS:
  // You may want to use a separate function to implement the 
  // recursive Depth-First-Search algorithm for finding all reachable cities
  // starting from a city using its direct routes to other cities, and their
  // connected cities, and so on and so forth until all cities along
  // reachable paths are traversed.

  // Use the general approach described in zyBook 20.6 Graphs: Depth-first search
  // Follow what Figure 20.6.1 presents

  // A suggested separate recursive function for the DFS part could be:
  // void depthFirstSearchReachableCities(
  //      cityGraph, // a collection of a STL collection type  
  //      string startingCity, 
  //      vector<string> &reachableCities, // list of cities to add reachable cities along the recursive call  
  //      set<string> &visitedCities); // list of cities to track if a city is already visited along DFS search
  // what would be the base condition? --> the startingCity is already visited

  // Hint for sorting: descending order of number of reachable cities and 
  //                   ascending alphabetical order of the city code as the tiebreaker
  // you can leverage the std::sort()
  // one way to do the two-level of sorting here is to first sort the list 
  // by City code in ascending order, 
  // then sort by number of reachable cities in descending order.

  // Creates a CityNode vector that stores the CityNodes that have been called by the recursive DFS function. This will be returned at the end ff the function once it has been sorted.
  vector<CityNode> orderedCityNodes;

// The function cannot operate on an empty graph. Check the size of the cities vector.
  if(cities.size() > 0) {
     // This creates a map called cityGraph. The key type is a string and the value type is a CityNode. A string from the cities vector will be mapped as a CityNode to the cityGraph. makeCityGraph will return an unordered_map
    // with the cities string vector and the trainRoutes as arguemnts to populate the graph as well as the directRoiutedCities from the trainRoutes vector, or the adjacency list of every CityNode.
    unordered_map<string, CityNode> cityGraph = makeCityGraph(cities, trainRoutes);
    // This set represents the cities that have been visited so far. It will be cleared after each city has been recursively traversed in the for loop below.
    set<string> visitedCities;
     // This vector stores the cities that are reachable from the starting city. After each recursive function call, the directRoutedCities will be added to this vector to idnciate that the starting city can reach these nodes.
    vector<string> reachableCities;
    // This for loop iterates through the size of the cities string vector. This size is equal to the size of the cityGraph unordered_map since every string element from the cities vector is a CityNode in the cityGraph map.
    for(int i = 0; i < cities.size(); ++i) {
        // This retrieves the element associated with the cities string vector. Since every city must be recrusvely searched via DFS, it is easier to use the cities vector instead of retrieiving the CityNode from the cityGraph.
        string startingCity = cities.at(i);
        // This calls the depthFIrstReahcableCities recursive function. Each iteration of the for loop will set a city as the starting city, where the DFS function will then recursively search its adjacent nodes. These adjacent nodes are accessed
        // through the directRoutedCities vector of each CityNode object in the cityGraph. The reachableCities vector will append every adjacent city to teh current starting city, including the starting city itself, if the element
        // has not been visited thus far. visitedCities is a set that will be used to determine if a CityNode has been visited in a current execution of the recursive DFS function.
        depthFirstSearchReachableCities(cityGraph, startingCity, reachableCities, visitedCities);
        // After the CityNode has been traversed from the recursive DFS and its reachable nodes have been updated, this will set the reachableCities vector data member of thec currnet CityNode object to this vector. This is achieved by a pass
        // by reference arguemnt using the reachableCities vector. Every CityNode that is considered adjacent, or an outgoing edge of the current starting city, is a reachable city from the starting source.
        cityGraph.at(startingCity).setReachableCities(reachableCities);
        // This is necessary because every loop iteration will require an empty set once a a CityNode has been traversed.
        visitedCities.clear();
        // This will remove all of the elements of the reachableCities vector because the order of reahcbaleCities will be different for every CityNode in the graph.
        reachableCities.clear();
    }

    for(int i = 0; i < cities.size(); i++) {
        // This stores every CityNode node from the cityGraph into a vector. This is necessary for the STL sort() method because it converts the graph into a collection that is more flexible to work with.
        orderedCityNodes.push_back(cityGraph.at(cities.at(i)));
    }
    // Sort the orderedCityNode vector using the iterators that point to the beginning of the vector and the end by alphabetical order. The overloaded < operator is called so that the sort function satisfies these properties.
    sort(orderedCityNodes.begin(), orderedCityNodes.end());
    // Sort the orderedCityNode vector using the iterators that point to the beginning of the vector and the end by descending size of reachable cities for each CityNode. The overloaded > operator is called so that the sort function satisfies these properties.
    sort(orderedCityNodes.begin(), orderedCityNodes.end(), greater<CityNode>());
  }

  return orderedCityNodes; // vector<CityNode>() here is a placeholder, you need to change it to 
                             // whichever the vector your logic comes up with and return

}
/**
* @param  cities  a list of cities with each city identified by a two letter code
 * @param trainRoutes  a string, string pair vector that stores a collection of cities and their respective outgoing or adjacent cities.
 *
 * @return       an unordered_map that stores CityNodes according the string key. These keys are unique and thus every CityNode will be stored in a unique psoition in the map.
 
* @see         
*/

unordered_map<string, CityNode> ConnectedCities::makeCityGraph(vector<string> cities, vector<pair<string, string>> trainRoutes) {
    // This declares an unordered_map that represents the graph that will store the CityNodes.
    unordered_map<string, CityNode> cityGraph;
     // This creates a pair that will store an element from the trainRoutes vector over the course of the graph construction.
    pair<string, string> trainRoute;

    for (int i = 0; i < cities.size(); ++i) {
        // Create a CityNode object with each sity passed as an argument to the CityNode constructor. This ensures that every city from cities vector will be created as a CityNode in the graph.
        CityNode curNode(cities.at(i));
        // Inserts the new CityNode object into the graph according to the city. The city name is the key, which is assumed to be unique.
        cityGraph.emplace(cities.at(i), curNode);
    }

    // This for loop is necessary becuase it adds the adjacent cities to every corresponding city. The city that has an outgoing edge is the first element of the pair and the second element of the pair
    // is its adjacent city. Looping through all of these pairs in the vector will ensure that the graph is correct.
     for(int i = 0; i < trainRoutes.size(); ++i) {
        // Retrieve the city and its adjacent city pair.
        trainRoute = trainRoutes.at(i);
        // Using, the city, or the first element of the pair, add the adjacent city to the CityNode's vector of directRoutedCities using the second element of the pair.
        cityGraph.at(trainRoute.first).addADirectRoutedCity(trainRoute.second);
    } 
    // Return the graph after all of the adjacent cities are added to the graph of CityNodes.
    return cityGraph;
}

/**
* @param cityGraph an unordred_map that represents a collection of CityNodes with its adjacent and reahcable cities as data members.
* @param startingCity a string that represents the current city that has been traversed in the recursive function.
* @param  reachableCities  a vector of cities that represents the collection of cities that are reahcable from the single source city.
 * @param visitedCities  a set of string cities that represents a unique collection of cities. If a city has already been visited, it will be present in this set.
 *
 * 
 
* @see         
*/
 void ConnectedCities::depthFirstSearchReachableCities(unordered_map<string, CityNode> cityGraph, string startingCity, vector<string> &reachableCities, set<string> &visitedCities) {
    // This checks to see if the startingCity, or the current city in the graph, has already been visited.
     if(!visitedCities.count(startingCity)) {
        // Add the current city to the vector of reachable or adjacent cities. This indicates that this city can be reached from the single soruce city.
        reachableCities.push_back(startingCity);
        // Add this city to teh set of visitedCities to indicate that this city has already been visited.
        visitedCities.insert(startingCity);
        // This for loops iterates through the current city's adjacent cities. This is necessary because if the path follows along one adjacent city to the end where there are no more outgoing edges, it will return to 
        // the function where other adjacent elements could be traversed from. This ensures that every CityNode will be visited along the DFS.
        for(int i = 0; i < cityGraph.at(startingCity).getDirectRoutedCities().size() ; ++i) {
            // Set the new current city to an adjacent or direct routed city. 
            string newStartingCity = cityGraph.at(startingCity).getDirectRoutedCities().at(i);
            // Recursively call the function again with each of these adjacent nodes.
            depthFirstSearchReachableCities(cityGraph, newStartingCity, reachableCities, visitedCities);
        }
        
     }
    
} 
// Overloads the < oeprator to ensure that the sort function by alphabetical order can execute.
bool operator<(const CityNode &lhs, const CityNode &rhs) {
    // Returns true if the city string of the left CItyNode object is less than the city string name of the right CityNode object.
    return lhs.getReachableCities().at(0) < rhs.getReachableCities().at(0);
}
// Overloads the > oeprator to ensure that the sort function by size of the reachableCities vector can execute.
bool operator>(const CityNode& lhs, const CityNode& rhs) {
    // Returns true if the size of the reachableCities vector of the left CityNode object is greater than the size of the reachableCities vector of the right CityNode object.
    return lhs.getReachableCities().size() > rhs.getReachableCities().size();
}

 
