// this sketch is very strange.
// k is initialised in the hline file with value one
// but quicktrialsketch sees it with value zero before the hline
// object is created, and with value one after

          int k = 1;

          class HLine {
            float ypos, speed;
            int toBeInitialised = 1;
            HLine () {
               ypos = 2;
               speed = 3;
            
               println("start initialising HLine");
               //draw();
               println("a from kline:" + a);
               println("k from kline:" + k);
               println("finish initialising HLine");
               
               //line(0,0,random(0,100),random(0,100));
         
            }

            void printSomething() {
               println("printing something");
            }

          }

