void setup() {
  System.out.println(">>> doing size");
  size(320,480);
  System.out.println(">>> done size");
}

void draw() {
    System.out.println(">>> start of draw " + frameCount);
    if (frameCount == 1) return;
    line(0,0,50,50);
    rect(10,10,20,20);    
    triangle(10,13,23,56,45,67);
    System.out.println(">>> end of draw");
}


