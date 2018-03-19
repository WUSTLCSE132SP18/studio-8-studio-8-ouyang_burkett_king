package studio8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

// TODO: Develop an algorithm to count steps in accelerometer data
//    Major steeps:
//       1. Create a class and main method.
//       2. Using a Scanner and File object, read data from your .csv file.
//       3. Develop and test algorithms to count the "peaks" in the data.

public class CountSteps
{
	public static void main(String[] args)
	{
		int count = 0; 
		File steps = new File("data/data.csv");
		try {
			Scanner scan = new Scanner(steps);
			double [] current = new double[3]; 
			while(scan.hasNext())
			{
				String line = scan.nextLine();
				String [] dcurent = line.split(",");
				
				double storage1 = current[1];
				double storage2 = current[2];
				current[0] =  storage1;
				current[1] = storage2;
				current[2] = Double.parseDouble(dcurent[0]);
				
				if(current[1] > current[0] && current[1] >= current[2] && current[1] > 1.5)
				{
					count++; 
				}
				
			}
			
			System.out.print(count);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
