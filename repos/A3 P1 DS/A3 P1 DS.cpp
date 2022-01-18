#include<iostream>
using namespace std;
int arr[3][3];
int player = 1, opponent = 2;
class TicTacToe
{
public:
	void input()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];
		}
	}
	void invaild()
	{
		int noone = 0;
		int notwo = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 1)
					noone++;
				if (arr[i][j] == 2)
					notwo++;
			}
		}
		int min, max;
		if (noone < notwo)
		{
			min = noone;
			max = notwo;
		}
		else
		{
			min = notwo;
			max = noone;
		}
		if (min == max)
		{
			player = 1;
			opponent = 2;
			return;
		}

		if (min + 1 != max)
		{

			cout << "-1";
			exit(0);
		}
		else
		{

			if (noone < notwo)
			{
				player = 1;
				opponent = 2;
			}
			else
			{
				player = 2;
				opponent = 1;
			}
		}
	}
	void Draw()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (arr[i][j] == 0)
					return;
		}
		cout << "0";
		exit(0);
	}
	void solve()
	{
		Draw();
		int ans = checkwinner();
		if (ans == 1 || ans == 2)
			cout << ans;
		play(player);
		play(opponent);

	}
	void play(int player)
	{
		int best = -999999;
		int bestx = -1;
		int besty = -1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 0)
				{
					arr[i][j] = player;
					int tempbest = fun(player, true);
					arr[i][j] = 0;
					if (tempbest > best)
					{
						bestx = i;
						besty = j;
						best = tempbest;
					}

				}
			}
		}
		arr[bestx][besty] = player;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	int fun(int player, bool IsMax)
	{
		if (IsMax)
		{
			int best = -99999;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (arr[i][j] == 0)
					{
						arr[i][j] = player;
						best = max(best, fun(player, !IsMax));
						arr[i][j] = 0;
					}
				}
			}
			return best;
		}
		else
		{
			int best = -99999;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (arr[i][j] == 0)
					{
						arr[i][j] = opponent;
						best = min(best, fun(opponent, !IsMax));
						arr[i][j] = 0;
					}
				}
			}
			return best;
		}
	}
	int checkwinner()
	{
		for (int row = 0; row < 3; row++)
		{
			if (arr[row][0] == arr[row][1] && arr[row][0] == arr[row][2])
				return arr[row][0];
		}
		for (int col = 0; col < 3; col++)
		{
			if (arr[0][col] == arr[1][col] && arr[0][col] == arr[2][col])
				return arr[0][col];
		}
		if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
		{
			return arr[0][0];
		}
		if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
			return arr[0][2];
		return 100;
	}

};
int main()
{
	TicTacToe obj;
	obj.input();
	obj.invaild();
	obj.solve();
}