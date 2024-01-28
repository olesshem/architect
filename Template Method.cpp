#include <iostream>
#include <string>

// Абстрактний базовий клас
class ReportGenerator {
public:
    void GenerateReport() {
        GatherData();
        AnalyzeData();
        FormatReport();
        PrintReport();
    }

protected:
    virtual void GatherData() = 0;
    virtual void AnalyzeData() = 0;
    virtual void FormatReport() {
        std::cout << "Форматування звіту у стандартному стилі" << std::endl;
    }
    virtual void PrintReport() = 0;
};

// Конкретний клас для фінансового звіту
class FinancialReportGenerator : public ReportGenerator {
protected:
    void GatherData() override {
        std::cout << "Збір фінансових даних" << std::endl;
    }

    void AnalyzeData() override {
        std::cout << "Аналіз фінансових даних" << std::endl;
    }

    void PrintReport() override {
        std::cout << "Друк фінансового звіту" << std::endl;
    }
};

// Конкретний клас для маркетингового звіту
class MarketingReportGenerator : public ReportGenerator {
protected:
    void GatherData() override {
        std::cout << "Збір маркетингових даних" << std::endl;
    }

    void AnalyzeData() override {
        std::cout << "Аналіз маркетингових даних" << std::endl;
    }

    void FormatReport() override {
        std::cout << "Форматування звіту з маркетинговими акцентами" << std::endl;
    }

    void PrintReport() override {
        std::cout << "Друк маркетингового звіту" << std::endl;
    }
};

int main() {
    FinancialReportGenerator financialReport;
    MarketingReportGenerator marketingReport;

    std::cout << "Фінансовий звіт:" << std::endl;
    financialReport.GenerateReport();

    std::cout << "\nМаркетинговий звіт:" << std::endl;
    marketingReport.GenerateReport();

    return 0;
}
