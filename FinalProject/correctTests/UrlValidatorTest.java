//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest {
   public UrlValidatorTest(String testName) {
      
   }
   
   public void testEquals(String url, boolean result, boolean expected) {
      if(result != expected) {
         System.out.println("Failed: " + url);
         System.out.println("    expected: " + expected);
         System.out.println("    result: " + result);
         System.out.println();
      }
      else{
         System.out.println("Passed: " + url);
         System.out.println();
      }
   }

   public void testManualTest(ResultPair[] tests) {	   
	   System.out.println("Starting Manual Test");
	   System.out.flush();
	   
	   // Create validator object
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   // loop through manual test resultPairs and see if they pass
	   boolean result;
	   boolean expected;
	   for(int i = 0; i < tests.length; ++i) {
	      result = urlVal.isValid(tests[i].item);
	      expected = tests[i].valid;
	      testEquals(tests[i].item, result, expected);
	      System.out.flush();
	      //Assert.assertEquals(tests[i].item, expected, result);
	   }
	   
	   System.out.println("End of Manual Test");
	   System.out.println();
	   System.out.println();
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
      
      ResultPair[] partitionTests1 = { 
         new ResultPair("http://www.google.com", true)
      };
      
      fct.testManualTest(manualTestPairs);
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testIsValid();
   }
   
}
