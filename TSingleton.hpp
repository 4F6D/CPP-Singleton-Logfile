#ifndef TSINGLETON
#define TSINGLETON

template <class T>
class TSingleton
{
protected:
	// Member variables
	static T* m_pSingleton;	// Static object

public:
	// Memberfunctions

	//Destructor
	//
	virtual ~TSingleton()
	{

	}

	// Get
	//
	inline static T* Get()
	{
		// Does the instance already exist?
		if (!m_pSingleton)
		{
			m_pSingleton = new T;	// No, then create new instance
		}

		// Return pointer to the instance
		return (m_pSingleton);
	}

	// Release static object
	static void Del()
	{
		if (m_pSingleton)
		{
			delete (m_pSingleton);
			m_pSingleton = NULL;
		}
	}
};

// Create static variable
template <class T>
T* TSingleton<T>::m_pSingleton = 0;

#endif
