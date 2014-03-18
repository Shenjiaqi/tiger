#ifndef __EMMSG_H__
#define __EMMSG_H__
extern bool EM_anyErrors;

void EM_newline(void);

extern int EM_tokPos;

void EM_error(int, string,...);
void EM_impossible(string,...);
void EM_reset(string filename);
// output pos
void EM_pos(int pos);
#endif
