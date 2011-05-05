float gravity = 6.0;
float mass = 2.0;
int numSprings = 5;
int theInts[] = new int[3];
Spring springs[] = new Spring[numSprings];

void setup() 
{
  size(320, 480);
  smooth();
  fill(255);
	
	for (int i=0; i<numSprings; i++) {
		springs[i] = new Spring(0.0, width/2, mass, gravity);
	}
}

void draw() 
{
  //hint(ENABLE_OPENGL_4X_SMOOTH);
  background(0);
	for (int i=0; i<numSprings; i++) {
		if (i==0) {
			//if (mouseX && mouseY) {
                                //println(mouseX + " " + mouseY);
				springs[i].update(mouseX, mouseY);
				springs[i].display(mouseX, mouseY);
			//} else {
			//	springs[i].update(width/2, height/2);
			//	springs[i].display(width/2, height/2);
			//}
		} else {
			springs[i].update(springs[i-1].x, springs[i-1].y);
			springs[i].display(springs[i-1].x, springs[i-1].y);
		}
	}
}
