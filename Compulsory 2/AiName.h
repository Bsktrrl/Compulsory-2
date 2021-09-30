string aiName() {
	string aiName{};
	int rngMax{10};

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> RNG(0, rngMax);
	int nameNumber = RNG(gen);

	if (nameNumber == 0)
		aiName = "Sarah";
	if (nameNumber == 1)
		aiName = "Bendik";
	if (nameNumber == 2)
		aiName = "Helene";
	if (nameNumber == 3)
		aiName = "Simon";
	if (nameNumber == 4)
		aiName = "Solveig";
	if (nameNumber == 5)
		aiName = "Ronny";
	if (nameNumber == 6)
		aiName = "Pernille";
	if (nameNumber == 7)
		aiName = "Sigurd";
	if (nameNumber == 8)
		aiName = "Ingvild";
	if (nameNumber == 9)
		aiName = "Gunnar";
	if (nameNumber == 10)
		aiName = "Elisabeth";

	return aiName;
}