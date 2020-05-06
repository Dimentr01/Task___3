#include <string>

bool Equal(std::string a, std::string b)
{
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++)
		{
			if (toupper(a[i]) != toupper(b[i]))
				return false;
		}

		return true;
	}
	return false;
}
