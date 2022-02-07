#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;


int placeTrade() 
{
	int r;
	r = 1+(rand()%10); // Generates a random number 1-10
	return r;		   // return random number
}



int main()
{ 
	int accBalance = 1000; 
	int tradesWon = 0;
	int tradesLost = 0;
	int profitPerTrade = 0;
	int lossPerTrade = 0;
	int longestWinStreak = 0;
	int currentWinStreak = 0;
	int longestLossStreak = 0;
	int currentLossStreak = 0;


	srand(time(0));

	for (int x = 0; x < 80; x++) // Plays simulation X times
	{
		if (placeTrade() <= 3) // % chance of winning followed by win/loss condition
		{
			currentWinStreak++;	
			if (currentWinStreak > longestWinStreak)
			{
				longestWinStreak = currentWinStreak;
			}
			cout << "Trade Win!" << endl;
			accBalance = accBalance + 15;
			tradesWon = tradesWon + 1;
			profitPerTrade = profitPerTrade + 15;
			currentLossStreak = 0;
		}
		else
		{
			currentLossStreak++;
			if (currentLossStreak > longestLossStreak)
			{
				longestLossStreak = currentLossStreak;
			}
			cout << "Stop out." << endl; 
			accBalance = accBalance - 5;
			tradesLost = tradesLost + 1;
			lossPerTrade = lossPerTrade + 5;
			currentWinStreak = 0;
		}
	}
	cout << " -----------------------Trade simulation complete------------------------------- " << endl;
	cout << "Your account balance is $" << accBalance << endl;
	cout << "# of Trades won " << tradesWon << ". " << endl; 
	cout << "Profit from winning trades $" << profitPerTrade << endl;
	cout << "# of Trades lost. " << tradesLost << endl; 
	cout << "Total loss from losing trades $" << lossPerTrade << endl;
	cout << "Longest win streak is " << longestWinStreak << ". " << endl;
	cout << "Longest losing streak is " << longestLossStreak << ". " << endl;
	cout << "Trade expectancy " << (0.3 * 12) - (0.7 * 1.5) << endl; // (% winrate * average win(in ticks)) - (% lossrate * average loser(in ticks)) change values to your stats.
	 
	
	if (profitPerTrade > lossPerTrade)
	{
		int netGain = profitPerTrade - lossPerTrade;
		cout << "Total gain: $" << netGain << endl;
	}
	else
	{
		int netLoss = lossPerTrade - profitPerTrade;
		cout << "Total loss: -$" << netLoss << endl;
	}

	
}