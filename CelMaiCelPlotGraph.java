/**
* CelMaiCelPlotGraph program implements a simple graph plotter
*
* @author Dan Andrei Iliescu
*/

public class CelMaiCelPlotGraph
{
  public static void main(String[] args)
  {
    // Read function string
    CelMaiCelExpressionString functie = new CelMaiCelExpressionString(args[0]);
    
    // Read size and scale
    int sizeX = Integer.parseInt(args[1]);
    int sizeY = Integer.parseInt(args[2]);
    int scaraX = Integer.parseInt(args[3]);
    int scaraY = Integer.parseInt(args[4]);
    
    // Compute midway
    int midwayX = sizeX / 2;
    int midwayY = sizeY / 2 + 1;
    
    char matrix[][] = new char[sizeY][sizeX];
    
    int row, column;
    
    double rezultat;
    
    for(row = 0; row < sizeY; row ++)
      for(column = 0; column < sizeX; column ++)
        if(row == midwayY - 1 || column == midwayX - 1)
          matrix[row][column] = '=';
        else
          matrix[row][column] = ' ';
          
    for(column = 0; column < sizeX; column ++)
    {
      rezultat = functie.interpret((double) (column + 1 - midwayX) / scaraX) * scaraY;
      row = sizeY - midwayY - (int) rezultat;
      
      if(row < sizeY && row >= 0)
        matrix[row][column] = 'O';
    }
    
    System.out.println("\n\nIACA GRAFICUL:");
    
    for(row = 0; row < sizeY; row ++)
    {
      for(column = 0; column < sizeX; column ++)
        System.out.print(matrix[row][column]);
      System.out.println(' ');
    }
    
    System.out.println("\n\n");
  }
}
