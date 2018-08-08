//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest {


   public UrlValidatorTest(String testName) {
      //super(testName);
   }
   
   
   public void testManualTest()
   {
      //You can use this function to implement your manual testing	   
	   System.out.println("manual test");
   }
   
   
   public void testYourFirstPartition()
   {
      //You can use this function to implement your First Partition testing
      System.out.println("p1 test");
   }
   
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
      System.out.println("p2 test");
   }
   //You need to create more test cases for your Partitions if you need to 
   
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
      System.out.println("programming test");
   }
   

   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   
	   fct.testManualTest();
	   fct.testYourFirstPartition();
	   fct.testYourSecondPartition();
	   fct.testIsValid();
   }
}
