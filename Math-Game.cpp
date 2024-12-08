#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel QuetionLevel;
	enOpType OpType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult;
};

struct stQuizResults
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionsLevel QuetionLevel;
	enOpType OpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool isPass;
};

int randnum(int from, int to)
{
	int num = rand() % (to - from + 1) + from;
	return num;
}

short ReadHowManyQuestions()
{
	int num;
	do
	{
		cout << "How Many Questions do you want to answer ? 1 to 10 ? ";
		cin >> num;
	} while (num < 1 || num > 10);

	return num;
}

enQuestionsLevel ReadQuetionsLevel()
{
	short LevelType;
	cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	cin >> LevelType;
	return (enQuestionsLevel)LevelType;
}

enOpType ReadOpType()
{
	short OpType;
	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
	cin >> OpType;
	return (enOpType)OpType;
}

int SimpleCalculator(enOpType OpType, int Number1, int Number2)
{
	switch (OpType)
	{
	case Add:
		return Number1 + Number2;
		break;
	case Sub:
		return Number1 - Number2;
		break;
	case Mul:
		return Number1 * Number2;
		break;
	case Div:
		return Number1 / Number2;
		break;
	default:
		return Number1 + Number2;
		break;
	}
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOpType OpType)
{
	stQuestion Question;
	if (QuestionLevel == enQuestionsLevel::Mix)
	{
		QuestionLevel = (enQuestionsLevel)randnum(1, 3);
	}
	if (OpType == enOpType::MixOp)
	{
		OpType = (enOpType)randnum(1, 4);
	}

	Question.OpType = OpType;

	switch (QuestionLevel)
	{
	case Easy:
		Question.Number1 = randnum(1, 10);
		Question.Number2 = randnum(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.OpType, Question.Number1, Question.Number2);
		Question.QuetionLevel = QuestionLevel;
		return Question;
		break;
	case Med:
		Question.Number1 = randnum(10, 50);
		Question.Number2 = randnum(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.OpType, Question.Number1, Question.Number2);
		Question.QuetionLevel = QuestionLevel;
		return Question;
		break;
	case Hard:
		Question.Number1 = randnum(50, 100);
		Question.Number2 = randnum(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.OpType, Question.Number1, Question.Number2);
		Question.QuetionLevel = QuestionLevel;
		return Question;
		break;
	}
	return Question;
}

void GenerateQuetions(stQuizResults& Quiz)
{
	for (short Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionList[Question] = GenerateQuestion(Quiz.QuetionLevel, Quiz.OpType);
	}
}

string GetOpSymbol(enOpType OpType)
{
	switch (OpType)
	{
	case Add:
		return "+";
		break;
	case Sub:
		return "-";
		break;
	case Mul:
		return "*";
		break;
	case Div:
		return "/";
		break;
	case MixOp:
		return "Mix";
		break;
	}
}

void PrintQuestion(stQuizResults Quiz,short QuestionNumber)
{
	cout << "\n\n Question [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]\n";
	cout << Quiz.QuestionList[QuestionNumber].Number1 << "\n";
	cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpSymbol(Quiz.QuestionList[QuestionNumber].OpType);
	cout << "\n__________\n";
	cout << "= ";
}

int ReadQuestionAnwer()
{
	int Answer;
	cin >> Answer;
	return Answer;
}

void SetScreenQuestionColor(bool AnswerResult)
{
	if (AnswerResult)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

void CorrectQuestionAnswer(stQuizResults& Quiz, short QuestionNumber)
{
	if (Quiz.QuestionList[QuestionNumber].PlayerAnswer == Quiz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer (-:\n";
		
	}
	else
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer )-:\n";
		cout << "The Result is : " << Quiz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}

	SetScreenQuestionColor(Quiz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectTheQuestionAnswer(stQuizResults& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintQuestion(Quiz, QuestionNumber);
		Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnwer();
		CorrectQuestionAnswer(Quiz, QuestionNumber);
	}
	Quiz.isPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResultText(bool isPass)
{
	if (isPass)
		return "Pass (-:";
	else
		return "Fail )-:";
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

void SetScreenFinalResultColor(bool isPass)
{
	if (isPass)
		system("color 2F");
	else
		system("color 4F");
}

void PrintFinalQuizResults(stQuizResults Quiz)
{
	SetScreenFinalResultColor(Quiz.isPass);
	cout << "__________________________________\n\n";
	cout << "     Final Result is " << GetFinalResultText(Quiz.isPass);
	cout << "\n__________________________________\n\n";
	cout << "Number Of Questions         : " << Quiz.NumberOfQuestions << endl;
	cout << "Question Level              : " << GetQuestionLevelText(Quiz.QuetionLevel) << endl;
	cout << "OpType                      : " << GetOpSymbol(Quiz.OpType) << endl;
	cout << "Number Of Right Answer      : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answer      : " << Quiz.NumberOfWrongAnswers << endl;
	cout << "__________________________________\n";
}

void PlayMathGame()
{
	stQuizResults Quiz;
	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuetionLevel = ReadQuetionsLevel();
	Quiz.OpType = ReadOpType();

	GenerateQuetions(Quiz);
	AskAndCorrectTheQuestionAnswer(Quiz);
	PrintFinalQuizResults(Quiz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartMathGame()
{

	char PlayAgain = 'y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "Do you want to play again ? [Y] yes, [N] no ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
	srand((unsigned)time(NULL));

	StartMathGame();

	return 0;
}

