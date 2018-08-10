//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest {
   public UrlValidatorTest(String testName) {
      
   }
   
   public void testEquals(String url, boolean result, boolean expected) {
      if(value != expected) {
         System.out.println("Failed- " + url);
         System.out.println("    expected: " + expected);
         System.out.println("    result: " + result);
         System.out.println();
      }
   }

   public void testManualTest(resultPairs[] tests) {	   
	   System.out.println("Starting Manual Test");
	   
	   // Set up validator object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // loop through manual test resultPairs and see if they pass
	   boolean result;
	   boolean expected
	   for(int i = 0; i < tests.length; i++) {
	      result = urlVal.isValid(tests[i].item);
	      expected = tests[i].valid;
	      testEquals(tests[i].item, result, expected);
	   }
	   
	   System.out.println("End of Manual Test");
   }
   
   public void testYourFirstPartition() {
      //You can use this function to implement your First Partition testing
      System.out.println("Starting First Partition Test");
      
   }
   
   public void testYourSecondPartition() {
		 //You can use this function to implement your Second Partition testing	   
      System.out.println("Starting Second Partition Test");
      
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid() {
	   //You can use this function for programming based testing
      System.out.println("Starting Programming Based Test");
      
   }

   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   
	   fct.testManualTest(manualTestPairs);
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testIsValid();
   }
   
   ResultPair[] manualTestPairs = {  new ResultPair("http://www.google.com", true),
                                        new ResultPair("http://www.google.com/", true),
                                        new ResultPair("https://www.oregonstate.edu/", true),
                                        new ResultPair("3ht://www.google.com:80/test1?action=view", false),
                                        new ResultPair("http://google:-80/test1?action=view", false),
                                        new ResultPair("http://www.google.com:80/..?action=view", false)};
                                        
   
}
