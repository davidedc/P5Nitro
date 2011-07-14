
// This sketch was supposed to help in bridging the gap between
// touch events and mouse events
// but looking at it again I can't understand what it's exactly
// supposed to do. I think this is eligible for deletion.


/* simulating touch interface, don't remove this line */int realMouseX = 0;
/* simulating touch interface, don't remove this line */int realMouseY = 0;

/* simulating touch interface, don't remove this line */int authenticMouseX = 0;
/* simulating touch interface, don't remove this line */int authenticMouseY = 0;




void setup() {
  size(320,480);
  System.out.println("setup");
}

void draw() {
  /* simulating touch interface, don't remove this line */  authenticMouseX = mouseX;
  /* simulating touch interface, don't remove this line */  authenticMouseY = mouseY;

  /* simulating touch interface, don't remove this line */  mouseX = realMouseX;
  /* simulating touch interface, don't remove this line */  mouseY = realMouseY;


  //System.out.println("mousePressed: " + mousePressed);




  /* simulating touch interface, don't remove this line */  mouseX = authenticMouseX;
  /* simulating touch interface, don't remove this line */  mouseY = authenticMouseY;
}

void mouseClicked() {

  /* simulating touch interface, don't remove this line */  realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */  realMouseY = mouseY;

  System.out.println("mouseClicked mouseX mouseY " + mouseX + " " + mouseY);
}

void mouseMoved() {
  //this should be empty - only mousedragged should be implemented
  System.out.println("mouseMoved shouldn't be used for touch");
}

void mouseDragged() {

  /* simulating touch interface, don't remove this line */  realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */  realMouseY = mouseY;
  System.out.println("mouseDragged mouseX mouseY " + mouseX + " " + mouseY);
}

void mousePressed() {

  /* simulating touch interface, don't remove this line */  realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */  realMouseY = mouseY;
  System.out.println("mousePressed mouseX mouseY " + mouseX + " " + mouseY);
}

void mouseReleased() {
  /* simulating touch interface, don't remove this line */  realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */  realMouseY = mouseY;
  System.out.println("mouseReleased mouseX mouseY " + mouseX + " " + mouseY);
}

