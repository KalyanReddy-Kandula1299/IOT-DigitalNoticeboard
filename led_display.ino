#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include <LiquidCrystal.h>
// size of buffer used to capture HTTP requests
#define REQ_BUF_SZ   90
// size of buffer that stores a line of text for the LCD + null terminator
#define LCD_BUF_SZ   17

// MAC address from Ethernet shield sticker under board
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x2B, 0x7B };
IPAddress ip(192,168,0,127);   // IP address, may need to change depending on network
EthernetServer server(80);       // create a server at port 80
File webFile;                    // the web page file on the SD card
char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;              // index into HTTP_req buffer
char lcd_buf_1[LCD_BUF_SZ] = {0};// buffer to save LCD line 1 text to
char lcd_buf_2[LCD_BUF_SZ] = {0};// buffer to save LCD line 2 text to


String  old_string="rkv";
String income_string="RGUKT";
int length_ofstring=income_string.length();
int loop_variable=6*(length_ofstring+4);
int completed=0;
int col_pin[12]={0,1,2,3,4,5,6,7,8,9,11,12};
int row_pin[6]={A0,A1,A2,A3,A4,A5};
int A[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,0,1},
                   };
int B[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,0,1,1},
             {1,0,0,1,1,1},
             {1,0,1,0,1,1},
             {1,0,0,0,0,1},
                   };
int C[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,1,1,1,1},
             {1,0,1,1,1,1},
             {1,0,0,0,0,1},
                   };
int D[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,1,1},
             {1,0,1,1,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,0,1},
             {1,0,0,0,1,1},
                   };
int E[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,0,0,0,1},
                   };
int F[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,1,1,1,1},
                   };
int G[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,0,1,1,1,1},
             {1,0,1,0,0,1},
             {1,0,1,1,0,1},
             {1,0,0,0,0,1},
                   };
int H[6][6]={{1,1,1,1,1,1},
             {1,0,1,1,0,1},
             {1,0,1,1,0,1},
             {1,0,0,0,0,1},
             {1,0,1,1,0,1},
             {1,0,1,1,0,1},
                   };
int I[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,1,0,1,1,1},
             {1,1,0,1,1,1},
             {1,1,0,1,1,1},
             {1,0,0,0,0,1},
                   };
int J[6][6]={{1,1,1,1,1,1},
             {1,0,0,0,0,1},
             {1,1,1,0,1,1},
             {1,1,1,0,1,1},
             {1,0,1,0,1,1},
             {1,0,0,0,1,1},
                   };
 int K[6][6]={{1,1,1,1,1,1},
              {1,0,1,1,0,1},
              {1,0,1,0,1,1},
              {1,0,0,1,1,1},
              {1,0,1,0,1,1},
              {1,0,1,1,0,1},
                   };
  int L[6][6]={{1,1,1,1,1,1},
               {1,0,1,1,1,1},
               {1,0,1,1,1,1},
               {1,0,1,1,1,1},
               {1,0,1,1,1,1},
               {1,0,0,0,0,1},
                   };
   int M[6][6]={{1,1,1,1,1,1},
                {1,0,1,1,1,0},
                {1,0,0,1,0,0},
                {1,0,1,0,1,0},
                {1,0,1,1,1,0},
                {1,0,1,1,1,0},
                   };
   int N[6][6]={{1,1,1,1,1,1},
                {1,0,1,1,1,0},
                {1,0,0,1,1,0},
                {1,0,1,0,1,0},
                {1,0,1,1,0,0},
                {1,0,1,1,1,0},
                   };
    int O[6][6]={{1,1,1,1,1,1},
                 {1,0,0,0,0,1},
                 {1,0,1,1,0,1},
                 {1,0,1,1,0,1},
                 {1,0,1,1,0,1},
                 {1,0,0,0,0,1},
                   };
     int P[6][6]={{1,1,1,1,1,1},
                  {1,0,0,0,1,1},
                  {1,0,1,0,1,1},
                  {1,0,0,0,1,1},
                  {1,0,1,1,1,1},
                  {1,0,1,1,1,1},
                   };
    int Q[6][6]={{1,1,1,1,1,1},
                 {1,0,0,0,0,1},
                 {1,0,1,1,0,1},
                 {1,0,1,1,0,1},
                 {1,0,0,0,0,1},
                 {1,0,0,0,0,0},
                   };
     int R[6][6]={{1,1,1,1,1,1},
                  {1,0,0,0,0,1},
                  {1,0,1,1,0,1},
                  {1,0,0,0,1,1},
                  {1,0,1,0,1,1},
                  {1,0,1,1,0,1},
                   };
         int Z[6][6]={{1,1,1,1,1,1},
                      {1,0,0,0,0,1},
                      {1,1,1,0,1,1},
                      {1,1,0,1,1,1},
                      {1,0,0,0,0,1},
                      {1,1,1,1,1,1},
                   };
    
void setup()
{
    // disable Ethernet chip
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
    
    Serial.begin(9600);       // for debugging
    for(int i=0;i<6;i++)
{
  pinMode(row_pin[i], OUTPUT);
}
for(int i=0;i<12;i++)
{
   pinMode(col_pin[i], OUTPUT);
}
    digitalWrite(row_pin[0],LOW);
    // Message on LCD
   
    
    // initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(4)) {
        Serial.println("ERROR - SD card initialization failed!");
        
        return;    // init failed
    }
    Serial.println("SUCCESS - SD card initialized.");
    // check for index.htm file
    if (!SD.exists("index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
        return;  // can't find index file
    }
    Serial.println("SUCCESS - Found index.htm file.");

    Ethernet.begin(mac, ip);  // initialize Ethernet device
    server.begin();           // start to listen for clients

    // End of initialization message on LCD + print IP address
   
}

void loop()
{
    EthernetClient client = server.available();  // try to get client
    
     newstringfind (income_string);
    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // limit the size of the stored received HTTP request
                // buffer first part of HTTP request in HTTP_req array (string)
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // save HTTP request character
                    req_index++;
                }
               
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    Serial.println(HTTP_req);
                    client.println("HTTP/1.1 200 OK");
                    // remainder of header follows below, depending on if
                    // web page or XML page is requested
                    // Ajax request - send XML file
                    if (StrContains(HTTP_req, "ajax_inputs")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/xml");
                        client.println("Connection: keep-alive");
                        client.println();
                        GetLcdText(lcd_buf_1, LCD_BUF_SZ);
                         income_string=lcd_buf_1;
                         
                       
                        
                        newstringfind (income_string);
                        
                    }
                    else {  // web page request
                         Serial.println(HTTP_req);
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        webFile = SD.open("index.htm");        // open web page file
                        if (webFile) {
                            while(webFile.available()) {
                                client.write(webFile.read()); // send web page to client
                            }
                            webFile.close();
                        }
                    }
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}

// get the two strings for the LCD from the incoming HTTP GET request
boolean GetLcdText(char *line1,  int len)
{
  boolean got_text = false;    // text received flag
  char *str_begin;             // pointer to start of text
  char *str_end;               // pointer to end of text
  int str_len = 0;
  int txt_index = 0;
  char *current_line;

  current_line = line1;

  // get pointer to the beginning of the text
  str_begin = strstr(HTTP_req, "&L1=");

  for (int j = 0; j < 1; j++) { // do for 2 lines of text
    if (str_begin != NULL) {
      str_begin = strstr(str_begin, "=");  // skip to the =
      str_begin += 1;                      // skip over the =
      str_end = strstr(str_begin, "&");

      if (str_end != NULL) {
        str_end[0] = 0;  // terminate the string
        str_len = strlen(str_begin);

        // copy the string to the buffer and replace %20 with space ' '
        for (int i = 0; i < str_len; i++) {
          if (str_begin[i] != '%') {
            if (str_begin[i] == 0) {
              // end of string
              break;
            }
            else {
              current_line[txt_index++] = str_begin[i];
              if (txt_index >= (len - 1)) {
                // keep the output string within bounds
                break;
              }
            }
          }
          else {
            // replace %20 with a space
            if ((str_begin[i + 1] == '2') && (str_begin[i + 2] == '0')) {
              current_line[txt_index++] = ' ';
              i += 2;
              if (txt_index >= (len - 1)) {
                // keep the output string within bounds
                break;
              }
            }
          }
        } // end for i loop
        // terminate the string
        current_line[txt_index] = 0;
        if (j == 0) {
          // got first line of text, now get second line
         
          txt_index = 0;
        }
        got_text = true;
      }
    }
  } // end for j loop

  return got_text;
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}
void  newstringfind (String test_string)
{
 
  if(test_string == old_string)
  { Serial.println("0");
    int length_ofstring=old_string.length();
     storage_string( income_string , length_ofstring);
    return 0;
  }
  else{
    old_string=test_string;
    int length_ofstring=income_string.length();
    int loop_variable=6*(length_ofstring+4);
    int completed=0;
     storage_string( income_string , length_ofstring);
    Serial.print("loop_variable is");
    Serial.println(loop_variable);
    return 1;
    }
}


int storage_string(String storage_string,int lenght_ofteststring)
{
char data[lenght_ofteststring];
storage_string.toCharArray(data,lenght_ofteststring+1);
int loop_variable=6*(lenght_ofteststring+4);
int datastore[6][loop_variable];
int datacount=0;
 int n=0;
  for(n=0;n<6;n++) 
  {      int i=0;
    
    datacount=0;
    for(i=0;i<loop_variable;)
     {
          if(i<12 || i>((lenght_ofteststring+2)*6-1))
          {
            datastore[n][i]=1;
            i++;
        
          }
          else
          {      
                   if(data[datacount]== 'a' || data[datacount]=='A') 
                   {
                               Serial.println("A");     
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=A[n][count];
                                            i++;    
                                        }
                                        datacount++;
                   }
                   
                    else if(data[datacount]== 'b'|| data[datacount]=='B')
                          {          Serial.println("B");    
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=B[n][count];
                                            i++;    
                                        }
                                        datacount++;
                                     
                          }
                     else if(data[datacount]== 'c'|| data[datacount]=='C')
                     {Serial.println("C");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=C[n][count];
                                            i++;    
                                        }
                                        datacount++;
                     }
                                      
                 
                    else if(data[datacount]== 'd'|| data[datacount]=='D')
                    {
                            Serial.println("D");          
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=D[n][count];
                                            i++;    
                                        }
                                        datacount++;
                    }
                  
                  else if(data[datacount]== 'e'|| data[datacount]=='E')
                  {Serial.println("E");   
                                    
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=E[n][count];
                                            i++;    
                                        }
                                        datacount++;
                  }
                else if(data[datacount]== 'f'|| data[datacount]=='F') 
                         {           Serial.println("F");    
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=F[n][count];
                                            i++;    
                                        }
                                        datacount++;
                                       
                         }        
                  else if(data[datacount]== 'g'|| data[datacount]=='G')
                       {           Serial.println("G");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=G[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                  else if(data[datacount]== 'h'|| data[datacount]=='H')
                     {              Serial.println("H");     
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=H[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                  else if(data[datacount]== 'i'|| data[datacount]=='I')
                       {         Serial.println("I");        
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=I[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 'j'|| data[datacount]=='J')
                       {         Serial.println("J");      
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=J[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                 else if(data[datacount]== 'k'|| data[datacount]=='K')
                          {           Serial.println("K");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=K[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 'l'|| data[datacount]=='L')
                       {            Serial.println("L");     
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=L[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                       
                 else if(data[datacount]== 'm'|| data[datacount]=='M')
                      {           Serial.println("M");       
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=M[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
              else if(data[datacount]== 'n'|| data[datacount]=='N') 
                    {                Serial.println("N");    
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=N[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 'o'|| data[datacount]=='O') 
                     {                Serial.println("O");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=O[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                  
                else if(data[datacount]== 'p'|| data[datacount]=='P')
                      {            Serial.println("P");      
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=P[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                 
                else if(data[datacount]== 'q'|| data[datacount]=='Q')
                      {             Serial.println("Q");   
                                          for(int count=0;count<6;count++)
                                          { 
                                             datastore[n][i]=Q[n][count];
                                              i++;    
                                          }
                                          datacount++;}
                                  
                else if(data[datacount]== 'r'|| data[datacount]=='R')
                     {               Serial.println("R");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=R[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                    
               else if(data[datacount]== 's'|| data[datacount]=='S')
                    {                 Serial.println("S");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=S[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 't'|| data[datacount]=='T')
                      {              Serial.println("T");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=T[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                 
                else if(data[datacount]== 'u'|| data[datacount]=='U') 
                   {                Serial.println("U");     
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=U[n][count];
                                            i++;    
                                        }
                                        datacount++;}
               else if(data[datacount]== 'v'|| data[datacount]=='V')
                   {                Serial.println("V");     
                                          for(int count=0;count<6;count++)
                                          { 
                                             datastore[n][i]=V[n][count];
                                              i++;    
                                          }
                                          datacount++;}
                                  
                else if(data[datacount]== 'w'|| data[datacount]=='W')
                   {                  Serial.println("W");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=W[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 'x'|| data[datacount]=='X')
                     {Serial.println("X");   
                                        for(int count=0;count<6;count++)
                                        { 
                                           datastore[n][i]=X[n][count];
                                            i++;    
                                        }
                                        datacount++;}
                                   
                else if(data[datacount]== 'y'|| data[datacount]=='Y')
                    {       Serial.println("Y");                       
                                                for(int count=0;count<6;count++)
                                                { 
                                                   datastore[n][i]=Y[n][count];
                                                    i++;    
                                                }
                                                datacount++;}
                                               
               else if(data[datacount]== 'z'|| data[datacount]=='Z')
                 {            Serial.println("Z");                   
                                              for(int count=0;count<6;count++)
                                              { 
                                                 datastore[n][i]=Z[n][count];
                                                  i++;    
                                              }
                                              datacount++;}
                                              
                 
                    
                              
                        
                
        }
 }

  }
completed=1;
for(int rr=0;rr<6;rr++)
{
  for(int xx=0;xx<30;xx++)
  {
    Serial.print(datastore[rr][xx]);
  }
  Serial.println();
}
  if(completed)
  {
     int m=0;
     int temp[6][12];
    for(m=0;m<(loop_variable-12);m++)
    {
        int n=0;
       
      for(n=0;n<6;n++)
        { int count=0;
          int i;
          for(i=m;i<(m+12);i++)
          { 
            temp[n][count]=datastore[n][i];
            count++;
          }
        }
        for(int mm=0;mm<6;mm++)
        {
          for(int yy=0;yy<12;yy++)
          {
            Serial.print(temp[mm][yy]);
          }
          Serial.println();
        }
         int x=0;
               for(x=0;x<400;x++)
             {  
                int nn=0;
                for(nn=0;nn<6;nn++)
                { 
                     int jj=0;
                  for(jj=0;jj<12;jj++)
                  {
                   if( temp[nn][jj]==1)
                   {
                        
                     digitalWrite(col_pin[jj],HIGH);
                   }
                    else if(temp[nn][jj]==0)
                    {
                      digitalWrite(col_pin[jj],LOW);
                    }
                    }
                   for(int pin=1;pin<6;pin++)
                   {
                      if(pin==nn)
                      {
                        digitalWrite(row_pin[pin],HIGH);
                      }
                      else
                      {
                        digitalWrite(row_pin[pin],LOW);
                      }
                   }
                      }
                   }
             
               }
            }
  
  return 0;
}
