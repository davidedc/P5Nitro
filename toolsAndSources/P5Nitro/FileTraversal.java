/*
Copyright (C) 2011 by all P5Nitro contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

import java.io.*;
import java.util.*;

public class FileTraversal {
  
	public final Vector nonRecursivelyListDirectoriesInside( final File f ) {
                try{

                Vector returnedListOfDirectories;
		if (f.isDirectory()) {
                        returnedListOfDirectories = new Vector();
			final File[] childs = f.listFiles();
			for( File child : childs ) {
                                if (child.isDirectory())
				  returnedListOfDirectories.add(child + "");
			}
			return returnedListOfDirectories;
		}
                return null;
                }
                catch (Exception e) {
                  System.out.println("Exception in function nonRecursivelyListDirectoriesInside:" + e);
                  return null;
                }
	}

	public final Vector nonRecursivelyListFilesInside( final File f ) throws IOException {
                Vector returnedListOfFiles;
		if (f.isDirectory()) {
                        returnedListOfFiles = new Vector();
			final File[] childs = f.listFiles();
			for( File child : childs ) {
                                if (child.isFile())
				  returnedListOfFiles.add(child + "");
			}
			return returnedListOfFiles;
		}
                return null;
	}

  	public final void traverse( final File f ) throws IOException {
		if (f.isDirectory()) {
			onDirectory(f);
			final File[] childs = f.listFiles();
			for( File child : childs ) {
				traverse(child);
			}
			return;
		}
		onFile(f);
	}

	public void onDirectory( final File d ) {
	}

	public void onFile( final File f ) {
	}
}

