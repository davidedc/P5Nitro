          class EHSVGGlyph {
            
            EHSVGPathParserAndDrawer commandParserAndDrawer;
            float horizAdv;
            String glyphID;

            EHSVGGlyph() {
              // do nothing in the constructor
            }

            public void loadCommandsPointsAndAdv(EHSVGPathParserAndDrawer theCommandParserAndDrawer, float theHorizAdv, String theGlyphID){
              horizAdv = theHorizAdv;
              glyphID = theGlyphID;
              commandParserAndDrawer = theCommandParserAndDrawer;
            }

          }

