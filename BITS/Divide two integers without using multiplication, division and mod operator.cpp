int divide(int dividend, int divisor) { 
  
  // Calculate sign of divisor i.e., 
  // sign will be negative only iff 
  // either one of them is negative 
  // otherwise it will be positive 
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
  
  // Update both divisor and 
  // dividend positive 
  dividend = abs(dividend); 
  divisor = abs(divisor); 
  
  // Initialize the quotient 
  int quotient = 0; 
  while (dividend >= divisor) { 
    dividend -= divisor; 
    ++quotient; 
  } 
  
  return sign * quotient; 
} 
//Time Complexity: 0(a), here a is divident
//Auxiliary Space : 0(1)
