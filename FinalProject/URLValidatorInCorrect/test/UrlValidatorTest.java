//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest {
   public UrlValidatorTest(String testName) {
      
   }
   
   public void testEquals(String url, boolean result, boolean expected) {
      if(result != expected) {
         System.out.println("X Failed: " + url + "    expected: " + expected + "    result: " + result);
         // System.out.println("    expected: " + expected);
         // System.out.println("    result: " + result);
      }
      else{
         System.out.println(". Passed: " + url + "    expected: " + expected + "    result: " + result);
         // System.out.println("    expected: " + expected);
         // System.out.println("    result: " + result);
      }
   }
   
   public boolean incrementIndex(Object[] testParts, int[] testPartsIndexes) {
      int i = 0; // This variable will index each int in the testPartsIndex array
      boolean rollsOver; // Switched to true if the current index loops back to zero
      int rollsOverCount = 0; // Used to keep track of how many indexes loop back to zero. If all of them loop back to zero then all combos have been tested

      do {
         rollsOver = false;
         
         // increment current index i
         testPartsIndexes[i]++;
         
         // if the index now equals the size of the resultPair array its indexing, loop back to zero and set rollsOver to true
         ResultPair[] part = (ResultPair[]) testParts[i];
         if(testPartsIndexes[i] >= part.length) {
            testPartsIndexes[i] = 0;
            rollsOver = true;
            rollsOverCount++;
         }
         
         // if rollsOverCount equal size of testPartsIndex array, then all the indexes have looped back to zero and testing is done.
         if(rollsOverCount == testPartsIndexes.length) {
            return false; // return false.. no more tests to do
         }
         
         i++;
      } while(rollsOver);
      return true; // more tests to do
   }

   public void testManualTest(ResultPair[] tests) {	   
	   System.out.println("Starting Manual Test");
	   
	   // Create validator object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // loop through manual test resultPairs and see if they pass
	   boolean result;
	   boolean expected;
	   for(int i = 0; i < tests.length; ++i) {
	      try {
	         result = urlVal.isValid(tests[i].item);
   	      expected = tests[i].valid;
   	      testEquals(tests[i].item, result, expected);
   	      //Assert.assertEquals(tests[i].item, expected, result);
	      }
	      catch(java.lang.ExceptionInInitializerError e) {
	         System.out.println("X Failed: " + tests[i].item + " " + e);
	      }
	      catch(Exception e) {
	         System.out.println("X Failed: " + tests[i].item + " " + e);
	      }
	   }
	   
	   System.out.println("End of Manual Test");
	   System.out.println();
	   System.out.println();
   }
   
   //tests schemes
   public void testYourFirstPartition() {

      System.out.println("Starting First Partition Test");
      System.out.println("Testing Schemes");
      UrlValidator myVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);         
         
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("3ht://www.google.com"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http:www.google.com"));
      System.out.println("Expected: False    Actual: " + myVal.isValid(""));
      System.out.println();
      System.out.println();
   }
   
   //tests authority
   public void testYourSecondPartition() {
  
      System.out.println("Starting Second Partition Test");
      System.out.println("Testing Authority");
      UrlValidator myVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);         
         
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.ca"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://255.255.255.255"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://256.256.256.256"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("fjzghjfdlhzgjfhdlzg"));
      System.out.println("Expected: False    Actual: " + myVal.isValid(""));
      System.out.println();
      System.out.println();
   }
   
      //tests port
   public void testYourThirdPartition() {
  
      System.out.println("Starting Third Partition Test");
      System.out.println("Testing Port");
      UrlValidator myVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);         
         
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com:0"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com:65535"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://www.google.com:65536"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://www.google.com:-1"));
      System.out.println("Expected: False    Actual: " + myVal.isValid(""));
      System.out.println();
      System.out.println();
   }
   
   // tests path
   public void testYourFourthPartition() {
  
      System.out.println("Starting Fourth Partition Test");
      System.out.println("Testing Path");
      UrlValidator myVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);         
         
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com/test1"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com/test1/"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://www.google.com/.."));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://www.google.com/test1//file"));
      System.out.println("Expected: False    Actual: " + myVal.isValid(""));
      System.out.println();
      System.out.println();
   }
  
  //tests path options 
   public void testYourFifthPartition() {
		   
      System.out.println("Starting Fifth Partition Test");
      System.out.println("Testing Query");
      UrlValidator myVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);         
         
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com?action=view"));
      System.out.println("Expected: True     Actual: " + myVal.isValid("http://www.google.com?action=edit&mode=up"));
      System.out.println("Expected: False    Actual: " + myVal.isValid("http://www.google.com&&&&&"));
      System.out.println("Expected: False    Actual: " + myVal.isValid(""));
      System.out.println();
      System.out.println();
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid(Object[] testParts, int[] testPartsIndex) {
	   //You can use this function for programming based testing
      System.out.println("Starting Programming Based Test");
      
	   // Create validator object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      
	   boolean result;
	   boolean expected;
	   
      // Loop until all combinations are tested
      do{
         // Build a url from parts objects using index object
	      StringBuilder testBuffer = new StringBuilder();
         expected = true;
         for(int i = 0; i < testPartsIndex.length; i++) {
            ResultPair[] part = (ResultPair[]) testParts[i];
            expected &= part[testPartsIndex[i]].valid; // Determine truth value and store in expected
            testBuffer.append(part[testPartsIndex[i]].item); // Append this url part to the string
         }
         
         try{
            // Call isValid and store return value in result
            result = urlVal.isValid(testBuffer.toString());
            
            // Call testEquals on result
            testEquals(testBuffer.toString(), result, expected);
         }
         catch(java.lang.NoClassDefFoundError e) {
	         System.out.println("X Failed: " + testBuffer.toString() + " " + e);
         }
         catch(Exception e) {
	         System.out.println("X Failed: " + testBuffer.toString() + " " + e);
         }
         
         
      } while(incrementIndex(testParts, testPartsIndex)); //increment index object
   }

   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   
	   // Results pairs for manual Tests
      ResultPair[] manualTestPairs = { 
         new ResultPair("http://www.google.com", true),
         new ResultPair("http://www.google.com/", true),
         new ResultPair("https://www.oregonstate.edu/", true),
         new ResultPair("3ht://www.google.com:80/test1?action=view", false),
         new ResultPair("http://google:80/test1?action=view", false),
         new ResultPair("http://www.google.com:-80/test1?action=view", false),
         new ResultPair("http://www.google.com:80/..?action=view", false),
         new ResultPair("eeee", false)
      };
      
      // Results pairs for programming based tests
      // The testIsValid method will take one result pair from each of these arrays and build a url with them to test
      // If any one of the resultPairs that make up a url have a false value the expected return value of the test will be false.
      ResultPair[] schemePart = { 
         new ResultPair("https://", true),
         new ResultPair("http://", true)
      };
      
      ResultPair[] authorityPart = { 
         new ResultPair("www.google.com", true),
         new ResultPair("www.go.com", true)
      };
      
      ResultPair[] portPart = { 
         new ResultPair("", true),
         new ResultPair(":80", true)
      };
      
      ResultPair[] pathPart = { 
         new ResultPair("/test1", true),
         new ResultPair("/test1/test2", true)
      };
      
      ResultPair[] queryPart = { 
         new ResultPair("?action=view", true)
      };
      
      Object[] testParts = {schemePart, authorityPart, portPart, pathPart, queryPart};
      int[] testPartsIndex = {0, 0, 0, 0, 0};
      
      
      // Call the testing methods
      fct.testManualTest(manualTestPairs);
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testYourThirdPartition();
	   fct.testYourFourthPartition();
	   fct.testYourFifthPartition();
	   fct.testIsValid(testParts, testPartsIndex);
   }
   
}
