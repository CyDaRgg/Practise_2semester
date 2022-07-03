#define lengthHash 12
#include"NomatchPassword.h"
struct nodeOfTree
{
	char hash[lengthHash + 1];
	int height;
	int repeats;
	struct nodeOfTree* left;
	struct nodeOfTree* right;
};

int NomatchPassword(struct nodeOfTree* root, char*hash)
{
	int static check = 1;
	int static count = 0;
	if (root)
	{
		if (root->left)
		{
			count++;
			NomatchPassword(root->left, hash);
		}
		if (root->right)
		{
			count++;
			NomatchPassword(root->right, hash);
		}
		if (strcmp(hash, root->hash) == 0)
		{
			count--;
			check = 0;
			return check;
		}
		if (count == 0)
		{

			if (check == 0)
			{
				check = 1;// для будущих
				return 0;
			}
			else
				return 1;
		}
		count--;
	}

	return check;
}
