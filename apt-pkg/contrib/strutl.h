// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
// $Id: strutl.h,v 1.13 1999/05/27 05:54:41 jgg Exp $
/* ######################################################################

   String Util - These are some usefull string functions
   
   _strstrip is a function to remove whitespace from the front and end
   of a string.
   
   This source is placed in the Public Domain, do with it what you will
   It was originally written by Jason Gunthorpe <jgg@gpu.srv.ualberta.ca>   
   
   ##################################################################### */
									/*}}}*/
#ifndef STRUTL_H
#define STRUTL_H

#ifdef __GNUG__
#pragma interface "apt-pkg/strutl.h"
#endif 

#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>

char *_strstrip(char *String);
char *_strtabexpand(char *String,size_t Len);
bool ParseQuoteWord(const char *&String,string &Res);
bool ParseCWord(const char *String,string &Res);
string QuoteString(string Str,const char *Bad);
string DeQuoteString(string Str);
string SizeToStr(double Bytes);
string TimeToStr(unsigned long Sec);
string SubstVar(string Str,string Subst,string Contents);
string Base64Encode(string Str);
string URItoFileName(string URI);
string TimeRFC1123(time_t Date);
bool StrToTime(string Val,time_t &Result);
string LookupTag(string Message,const char *Tag,const char *Default = 0);
int StringToBool(string Text,int Default = -1);
bool ReadMessages(int Fd, vector<string> &List);

int stringcmp(const char *A,const char *AEnd,const char *B,const char *BEnd);
inline int stringcmp(const char *A,const char *AEnd,const char *B) {return stringcmp(A,AEnd,B,B+strlen(B));};
inline int stringcmp(string A,const char *B) {return stringcmp(A.begin(),A.end(),B,B+strlen(B));};
int stringcasecmp(const char *A,const char *AEnd,const char *B,const char *BEnd);
inline int stringcasecmp(const char *A,const char *AEnd,const char *B) {return stringcasecmp(A,AEnd,B,B+strlen(B));};
inline int stringcasecmp(string A,const char *B) {return stringcasecmp(A.begin(),A.end(),B,B+strlen(B));};

class URI
{
   void CopyFrom(string From);
		 
   public:
   
   string Access;
   string User;
   string Password;
   string Host;
   string Path;
   unsigned int Port;
   
   operator string();
   inline void operator =(string From) {CopyFrom(From);};
   inline bool empty() {return Access.empty();};
   
   URI(string Path) {CopyFrom(Path);};
   URI() : Port(0) {};
};

#endif
