          class EhsvgGlyph {
            
            EHSVGPathParserAndDrawer commandParserAndDrawer;
            float horizAdv;
            String glyphID;

            EhsvgGlyph() {
              // do nothing in the constructor
            }

            public void loadCommandsPointsAndAdv(EHSVGPathParserAndDrawer theCommandParserAndDrawer, float theHorizAdv, String theGlyphID){
              horizAdv = theHorizAdv;
              glyphID = theGlyphID;
              commandParserAndDrawer = theCommandParserAndDrawer;
            }

          }

