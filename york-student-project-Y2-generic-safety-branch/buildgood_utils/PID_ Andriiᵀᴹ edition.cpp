int h_size = 10; // How many previous readings we want to remember
int history[10];
int target = 100; // Could be used as the second input for the function
int input = 0;
//Ridley was here
float PID(int input){
  // this code doesn't check for time since I suspect we will call the function on more or less regular intervals
  // therefore knowing the time isn't necessary for the Differential or the Integral
  // just have to make sure when tuning to write down somewherein here the sample frequency for that specific tuning parameters and not forget to change it
  float Kp = 1;
  float Ki = 1;
  float Kd = 1;

  // Changing the remembered values
  for(int i = 0; i<h_size-1; ++i){
    history[i] = history[i+1];
  } 
  history[h_size] = input;

  // Proportional
  int P = target - input;

  // Integral
  int I = 0;
  for(int i = 0; i<h_size; ++i){
    I = I + history[i];
  } 
  // an alternative to summing the entire history would be to substract the input that was just deleted from history and add the currently input,
  // however, I thought it would make the code more complicated and did this instead, despite this being technically slower.

  //Differential
  int D = (history[h_size] - history[0])/h_size;

  float output = Kp*P + Ki*I + Kd*D;
  return output;
}
