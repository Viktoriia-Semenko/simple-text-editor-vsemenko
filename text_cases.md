# Test cases for 'Simple Text Editor'
## Case 1
1. Append text to the end
2. Save text to file
   - The user is asked to write a name for the file to save text ( in format 'file_name.txt' )
   - If file already exists, user is asked whether he wants this file to be overwritten
      - if the answer is 'y', text that was before deletes and new is inserted
      - if the answer is 'n', new text is added to the start of a new line in that file
   - If file with this name not exists, text is appended to the new file
3. Print text
   - This command will print all text that were entered into the console
4. Start a new line
5. Append text to the end
6. Load
   - The user is asked for the name of the file for loading text from
   - Text that is loaded will be displayed in console
7. Print
   - in this test case on the console will be outputed all text that were inputed (not the text from files)

> [!NOTE]  
> After every command the user is asked whether he wants to continue

##### Result of the Case 1
<img width="882" alt="Знімок екрана 2024-05-27 о 00 04 55" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/41ffd059-44a3-4c48-9fa4-b7e2e5d55fc5">
<img width="758" alt="Знімок екрана 2024-05-27 о 00 15 51" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/c3e7b589-8cea-44bc-af79-4e6e13df23e7">


## Case 2
1. Append text to the end
2. Insert the text by line and symbol index
   - In this command user is asked to enter a line as a first number and index where to put text
   - If the input is invalid: when there is no text on entered line and index, the user is asked to
   - Then user is asked to enter a text to append
3. Save text to file
   - in this test case I choosed file that already exists and not ot overwrite it
4. Print text
5. Start a new line
6. Append text to the end
   - in this case text will be appended in new line
7. Search for the text
   - the user is asked to enter a text to search
   - If the text has been found, there will be displayed all the positions where this text was found (line index)
   - If text wasn't found there will be displayed such message 'There is no match for the given text'
8. Print text

##### Result of the Case 2
<img width="981" alt="Знімок екрана 2024-05-27 о 00 19 18" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/4d2a2c7c-0099-42d4-a246-ff6f9f316707">
<img width="673" alt="Знімок екрана 2024-05-27 о 00 19 30" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/7152cc4f-80ff-472d-b15d-90a7df2b0e47">
<img width="1045" alt="Знімок екрана 2024-05-27 о 00 31 06" src="https://github.com/Viktoriia-Semenko/simple-text-editor-vsemenko/assets/150340301/311b321f-7817-4754-8c9d-9004a95791de">








