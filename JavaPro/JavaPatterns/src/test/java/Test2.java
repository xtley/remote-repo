import java.util.Scanner;

public class Test2 {

	public static void main(String[] args) {
		input();

	}

	private static void input(){
		System.out.println("Please input your age??");
		Scanner input=new Scanner(System.in);
		//????
		String ageStr=input.next();
		//?????????
		Integer  ageInt = Integer.valueOf(ageStr);
		System.out.println("age??"+ageInt);
		
		System.out.println("please input your sex??");
		input=new Scanner(System.in);
		String sex = input.next();
		if("M".equalsIgnoreCase(sex)){
			System.out.println("Sex:M");
		}else if("F".equalsIgnoreCase(sex)){
			System.out.println("Sex:F");
		}
		
		System.out.println("please input your basic salary??");
		input=new Scanner(System.in);
		String basicSalaryStr = input.next();
		//?????????
		Integer  basicSalaryInt = Integer.valueOf(basicSalaryStr);

		System.out.println("basic salary"+basicSalaryInt);
		
		Integer finalSalary = null;
		finalSalary = basicSalaryInt;
		if(ageInt>25 && "M".equalsIgnoreCase(sex)){
			finalSalary = finalSalary+150;
		}
		if(ageInt>=50 || finalSalary >2000){
			finalSalary = finalSalary-200;
		}
		System.out.println("final salary??"+finalSalary);
//		input();
	}
}
