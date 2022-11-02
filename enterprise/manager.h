#ifndef MANAGER_H
#define MANAGER_H


class Manager
{
	int m_iId;
	char m_strName[20];
	char m_strPwd[20];
public:
	Manager(void);
	Manager(const char* name,const char* pwd);
	int getId(void)const;
	const char* getName(void)const;
	const char* getPwd(void)const;
	void setId(int id);
	void setName(const char* name);
	void setPwd(const char* pwd);
	
};

#endif//MANAGER_H
