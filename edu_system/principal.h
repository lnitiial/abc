#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else 
	#define debug(...)
#endif
void enter_pri(void);//进入校长页面

#endif//PRINCIPAL_H
