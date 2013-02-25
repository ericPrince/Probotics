
const double[] costs = {turn, 1, 2, 3, 4};

class Tile{
  boolean[] walls;    // used to check connections (in each dir)
  boolean   visited;  // has the tile been visited
  
  double travelCost;    // cost to get here
  double distanceCost;  // min cost to reach end
  Tile   pointer;       // previous tile in A* algorithm
  int    straightCount; // how long it has been going straight
  
  int x;  // x coordinate
  int y;  // y coordinate
  
  Tile(int n){
    walls = new boolean[4];
    visited = false;
    x = n%16;
    y = n/16;
  }
  
 // check this tile using A*
  void aStar(Tile last){
   // make this tile refer to the previous tile
    pointer = last;
    
   // update travel cost to go from last to this
    travelCost = pointer.travelCost;
      // if(this tile is not collinear with the last 2 tiles)
      //   add the travel cost for turning
      //   reset the num tiles traveled straight
    if(dirTo(pointer) != pointer.dirTo(pointer.pointer) 
        && pointer.dirTo(pointer.pointer) != -1){
      travelCost += costs[0];
      straightCount = 0;
    }
    else {
      straightCount++;
    }
    
    travelCost += costs[straightCount];
  }
  
 // get the index of the tile in a direction
  int dirTo(Tile other){
    if(other.x > x){ return 0; }
    if(other.x < x){ return 2; }
    if(other.y > y){ return 1; }
    if(other.y < y){ return 3; }
    return -1; // same tile
  }
  
 // use the sensors to check for walls
  void update(boolean[] sensors, int dir){
    if(visited){ return; }
    
    walls[(dir+3)%4] = sensors[0];
    walls[   dir   ] = sensors[1];
    walls[(dir+1)%4] = sensors[2];
    walls[(dir+2)%4] = false;
  }
  
 // reset the tile (after A*)
  void reset(){
    travelCost    = 0;
    distanceCost  = 0;
    pointer       = null;
    straightCount = 0;
  }
  
  int getIndex(int dir){
    int a = x;
    int b = y;
    
    if(dir==0){ a++; }
    if(dir==1){ b++; }
    if(dir==2){ a--; }
    if(dir==3){ b--; }
    
    return a%16 + b/16;
  }
  int getIndex(){
    return x%16 + y/16;
  }
}

// use A* algorithm to find optimal path
Tile[] calculatePath(Maze maze, Tile first, Tile last){
 // initialize set of open tiles
  ArrayList<Tile> openTiles = ArrayList<Tile>();
  
 // set initial conditions
  first.pointer = first;
  first.travelCost = 0;
  
 // run A* until final tile has been found
  Tile current = first;
  while(current != last){    
   // check each possible direction
    for(int i = 0; i < 4; i++){
      Tile test = maze.tile(current, i);
      
     // if tile in dir i has not been calculated? and no wall
      if(test.pointer == null && !test.walls[i]){
       // perform A* on test tile
        test.aStar(current);
        
       // add test tile into set of open tiles
        openTiles.add(test);
      }
    }
   // make current tile the tile with smallest heuristic
   // cost and remove it from the set of open tiles
    current = openTiles.remove();
  }// end of while loop
    
   // current tile is not an open tile anymore
   // all adjacent tiles have been added to set of open tiles
   
 // calculate path, working backwards
  path.add(current);
  ArrayList<Tile> path = ArrayList<Tile>();
  
  while(current.getIndex() != first.getIndex()){
    current = current.pointer;
    path.add(current, 0);
  }
  
 // clear all pointers and travelCosts
      // for each item in openTiles, follow pointer back and clear
  Tile toRemove;
  while(!paths.isEmpty){
    toRemove = paths.remove();
    while(toRemove.getIndex() != first.getIndex()){
      toRemove.pointer = null;
      toRemove.travelCost = 0;
      toRemove = toRemove.pointer;
    }
  }
 // turn path into an array and return it
  return path.toArray;
}

class Path{
  // custom linked list of tiles
  Node first;
  int size;
  
  Path(){
    size = 0;
    first = null;
  }
 // add a tile in the proper spot (sorted by heuristic cost)
  void add(Tile t){
    // have to redo later...
    Tile current = first;
    while(current.next != null 
           && t.heuristicCost() > current.next.heuristicCost()){
      current = current.next;
    }
    
  }
 // remove the tile with lowest heuristic cost
  Tile remove(){
    Item ans = first.Item;
    first = first.next;
  }
 // look at tile with lowest heuristic cost
  Tile peek(){
    return first.Item;
  }
 // check if there are no paths
  boolean isEmpty(){
    
  }
 // converts "linked list" to array
  Tile[] toArray(){
    
  }
  
  private class Node(){
    // contains tiles and links them
    Tile tile;
    Node next;
    
    Node(Tile t){
      tile = t;
    }
  }
}


class Maze{
  Tile[] tiles;
  
  Maze(int n){
    tiles = Tile[n*n];
  }
  
  Tile[] getMaze(){
    return tiles;
  }
  tile(Tile t, int dir){
    return // tile in direction dir;
  }
  
}
