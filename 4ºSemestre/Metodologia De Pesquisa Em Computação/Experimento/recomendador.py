#  SISTEMA ESPECIALISTA — RECOMENDAÇÃO DE LINGUAGENS
#  Forward Chaining com Ranking de Pontos (5 → 1)

# PERGUNTAS DO ARTIGO (Q01–Q11)
questions = {
    "Q01": "Você quer desenvolver Web Frontend? (s/n): ",
    "Q02": "Você quer desenvolver Web Backend? (s/n): ",
    "Q03": "Você quer desenvolver Aplicações Desktop? (s/n): ",
    "Q04": "Você quer desenvolver Aplicações Mobile? (s/n): ",
    "Q05": "Você quer desenvolver Jogos? (s/n): ",
    "Q06": "Você quer desenvolver IA? (s/n): ",
    "Q07": "Você quer trabalhar com Data Science? (s/n): ",
    "Q08": "Você quer trabalhar com Big Data? (s/n): ",
    "Q09": "Você quer usar Programação Orientada a Objetos? (s/n): ",
    "Q10": "Você quer usar uma linguagem interpretada? (s/n): ",
    "Q11": "Você quer usar uma linguagem compilada? (s/n): "
}

# TABELA DE PONTUAÇÃO REVISADA (ranking +5 a +1)
# Usei diferentes LLMs para gerar esta tabela e fiz uma média dos resultados
# Usei Chat-GPT, Claude, Gemini e Copilot
ranking = {
    "Q01": [("JavaScript",5), ("TypeScript",5), ("Python",2), ("Swift",1), ("Kotlin",1), ("Ruby",1)],
    "Q02": [("JavaScript",5), ("Python",5), ("TypeScript",4), ("Java",4), ("PHP",4), ("Go",3), ("C#",3), ("Ruby",3)],
    "Q03": [("C#",5), ("Java",5), ("Python",4), ("C++",4), ("Swift",2), ("Rust",1)],
    "Q04": [("Kotlin",5), ("Swift",5), ("Java",4), ("JavaScript",3), ("TypeScript",3), ("C#", 3)],
    "Q05": [("C++",5), ("C#",5), ("JavaScript",2), ("Rust",2), ("Python",2), ("Java",1), ("TypeScript",1), ("C",1)],
    "Q06": [("Python",5), ("C++",3), ("Java",3), ("Go",2), ("Rust",1), ("JavaScript",1), ("TypeScript",1)],
    "Q07": [("Python",5), ("Java",3), ("JavaScript",1), ("TypeScript",1)],
    "Q08": [("Java",5), ("Python",4), ("Go",3), ("Rust",2), ("C++",2)],
    "Q09": [("Java",5), ("C#",5), ("Python",4), ("C++",4), ("Kotlin",3), ("Swift",3), ("Ruby",3), ("TypeScript",1)],
    "Q10": [("Python",5), ("JavaScript",5), ("Ruby",5), ("PHP",4), ("TypeScript",3)],
    "Q11": [("C++",5), ("Rust",5), ("Go",5), ("C",5), ("C#", 4), ("Java", 4), ("Swift",4), ("Kotlin",4), ("TypeScript",1)]
}

# EXPLICAÇÃO DE CADA LINGUAGEM
descriptions = {
    "Python": "Extremamente simples, forte em IA, Data Science e automação.",
    "JavaScript": "A linguagem da Web, essencial para frontend e forte no backend com Node.",
    "TypeScript": "Versão tipada do JavaScript, ideal para projetos grandes e escaláveis.",
    "Java": "Muito usada no mercado, forte em backend, Android e sistemas grandes.",
    "C#": "Excelente para desktop e jogos com Unity.",
    "C++": "Altíssima performance; muito usado em jogos e sistemas críticos.",
    "C": "Baixo nível, ideal para sistemas embarcados.",
    "PHP": "Muito usado em backend web tradicional (WordPress, Laravel).",
    "Go": "Ótimo para servidores rápidos, concorrência e sistemas distribuídos.",
    "Rust": "Ultra seguro e rápido; ótimo para sistemas modernos e alto desempenho.",
    "Ruby": "Simplicidade extrema; forte no desenvolvimento rápido de aplicações web.",
    "Kotlin": "Linguagem oficial do Android moderna e segura.",
    "Swift": "Principal linguagem para iOS e macOS, moderna e rápida."
}

# MOTOR DE INFERÊNCIA (Forward Chaining por soma de pontos)
def ask_questions():
    answers = {}
    for key, text in questions.items():
        while True:
            ans = input(text).strip().lower()
            if ans in ["s", "n"]:
                answers[key] = ans
                break
            else:
                print("Digite apenas 's' ou 'n'.")
    return answers

def compute_scores(answers):
    scores = {lang:0 for lang in descriptions.keys()}

    for q, ans in answers.items():
        if ans == "s":  # só ganha pontos quem respondeu "sim"
            for lang, pts in ranking.get(q, []):
                scores[lang] += pts

    return scores

def recommend_language(scores):
    max_score = max(scores.values())
    best = [lang for lang, pts in scores.items() if pts == max_score]
    return best, max_score

# -----------------------------------------------------------
# PROGRAMA PRINCIPAL
# -----------------------------------------------------------

def main():
    print("\n==============================================")
    print("SISTEMA ESPECIALISTA — RECOMENDADOR DE LINGUAGENS")
    print("==============================================\n")

    answers = ask_questions()
    scores = compute_scores(answers)

    best_langs, max_pts = recommend_language(scores)

    print("\n----------------------------------------------")
    print("RESULTADO FINAL")
    print("----------------------------------------------")
    print(f"Maior pontuação: {max_pts} pontos\n")

    for lang in best_langs:
        print(f"▶ Linguagem recomendada: {lang}")
        print(f"   Explicação: {descriptions[lang]}\n")

    print("----------------------------------------------")
    print("Pontuação completa:")
    for lang, pts in sorted(scores.items(), key=lambda x: x[1], reverse=True):
        print(f"   {lang}: {pts} pontos")
    print("----------------------------------------------\n")

if __name__ == "__main__":
    main()
