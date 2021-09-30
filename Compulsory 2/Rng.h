int randomNumberGenerator(int numberMax) {
	int numberMin{1};

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> RNG(numberMin, numberMax);
	int randomNumber = RNG(gen);

	return randomNumber;
}