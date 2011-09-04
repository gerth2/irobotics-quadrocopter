void WritePWM(int north, int south, int east, int west)
{

//   in current assignment,
//   analog pin ------- motor  
//     3                east 
//     10               SOUTH
//     11               EAST
//     9                WEST
//    prints char 'd' when complete on successful write
//    prints char 'e' when completed and the write exceeded the maxrateofchange limit


  
  
  analogWrite(3, north);
  analogWrite(10, south);
  analogWrite(11, east);
  analogWrite(9, west);
  
  return;

}
