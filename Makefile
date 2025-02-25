NAME = philo
HEADER = philo.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
AR = ar -rcs
LIBFT = libft/libft.a

define HEADER
╔═════════════════════════════════════════════╗
║.______    __    __   __   __        ______  ║
║|   _  \  |  |  |  | |  | |  |      /  __  \ ║
║|  |_)  | |  |__|  | |  | |  |     |  |  |  |║
║|   ___/  |   __   | |  | |  |     |  |  |  |║
║|  |      |  |  |  | |  | |  `----.|  `--'  |║
║| _|      |__|  |__| |__| |_______| \______/ ║
║                                             ║
╚═════════════════════════════════════════════╝
endef
export HEADER

define ART
                                            ............                                            
                                      ..=#@@@@@@@%:@@@@@@@%+:                                       
                                ...+%@@@#=-::.:.+.*.-...::=#@@@%*:..                                
                              .-#@@%=:.:.%@-..::=+=:-..:@@+.=.:=#@@%=..                             
                          ..:#@@*:.#@+.*.-=.-@@@@@@@@*..--.%:%:+:.:*@@%-..                          
                         .-%@#:.--::%%-.*..%@@*..  =@@@.=.:.:-==-..=.:#@@=..                        
                       .:@@*.-..+@@@*:-%%:-**:-@@@*.+@@-.:@@@@@@@@@+.:#.+@@-.                       
                     ..:**.:%.#@@@@@%@@@@@@@@@@@@@@@@%.@@@@%: ...+@@@.:@#.+%:..                     
                    .=@%.+-==#@@=.=..::%%+::::.......:**=::#%%%::::@@+...#=.#@+.                    
                   .#@+.-#:*:%@@..=%*%@%%*-:#*=:*@@@@@#--%@@#-@@%.:@@+.#-.*=.=@%..                  
                  .*@-=-++-*--@@+-#**-*%%*:+@#=@@@+==+@@@#.-==*@*#:#@:.-*--*-+-@@.                  
                ..%%.-+:+*....-@=@@#=@@#%@@*-:%@%:%@@@+-@@#:@%-:@@@:.=*:+:.=:.+.=%:.                
                .@@::#=-#-.*=...:#@@*-:+*+@@-.%@@::=.%@=-@%::@@.%@@...-*@@@@=....@@:.               
               .*@=.-#..*#:....:*:@@%@@@*...::.=%@@%:@@-:*@@@@==@@=:@@@@@%%@@@#..-@#..              
              .=@#..:@+.....%:.%-@=+@#.+@@#.@@@@@-.@@+:@@@@#........+@...-#.-@@#:=*@*.              
              :%@.-::+#=-#*.  :@:@@+:--:.-@@=.:*+@@::=@@#:+.#@@+@@@@@#.::....%@%.:.%@:.             
             .=@*-*---++....:.:@#.*@@@@@@@*-#:@%-@@+=@@+-#@@@*-::::=@@@+.-:.+@@#...+@+.             
            ..%@-+*+::==**=-:.:@@@@#***-:%@@*.=*=.-#@@+=@@#-=**+::@@:+@@:%@@@@*.=*+:@@..            
            .:@%.*+==-.........@@@@@@@@+-+-%@@@@@@@@#-+*=*@=%@@@%:#%-+@@-+**-:.:+**:%@:             
            .-@*-####*++=:##-..@@%@@@#@@:#@+:-###*.:::=#@%*.:--:+%+-%@@*-@@@@@@%..*:*@=.            
            ..-............. .=@@@*-+#@@@==@*%@@@=@@@@@@::-@@@@@@==@@%..:-:...%@@::..-..            
            .=@*..............@@@@@@@@@@@@@-.=@@@=....@@@+=@%%=-@@=-@+*@@@@@%..@@*..*@=.            
            .-@#.:::.....*. .%@@@@@@@@@@@@@@@@@@@@@@@%.*@@*:::+:%@@=@+:-..%%:.+@@-:.#@-.            
            ..@@............@@@@@@@@@@@@@@@@@@@=:.=-@@@-+@@#.:.#@@-=@@@*..*@@@@%:-*.@@..            
             .#@-.**:=+:+=-..-*@@@@@@@@@@@@@@:#@@@@-.@@#.=@@@@@@@=++.+@@@#......:+.-@#..            
              =@*.%@-.....-=:.+@@@@@@@@@@@@@*%@@-+@#.@@%.*=:-=:.=@@..-.=@@*..-*-+%=+@=..            
              :%@..:-+#*:......%@@@@@@@@@@@@*%@@:+-:.@@%:@@@@@+:@@+-+...@@#..+#+-..%@:              
              .=@#.:+*:..:=+:..*@@@@@@@@@@@@@:*@@@@#.@@+.-%.=%@-#@@=...#@@+...*#-.#@+.              
               .#@=...+*....=#..@@@@@@@@@@@+=@@-.:...@@+.-#..@@#.#@@@@@@@-.%@@-#.=@#.               
               ..@@.:+#:-#-.....@@@@@@@*-*@@@@@@@@@@:*@@-:-:-@@%...:---..:..::*..@@:.               
                ..*@-=*-+*-=*-....:.......#@@@@@@@@@@-#@@@@@@@#.=..:+..:*==#:.=-@*..                
                  .-%-===*=...=+..+=..-..:.%@@@@@@@@@@*:=***+....=+..++-+.+*-+-%-.                  
                   .#@+.-*:-#:..+*...+.:#..+@@@@@@@@@@@%*+@@@+..*...:.-.==.%@+....                   
                    .=@%:-#:+-+*...+-..*..+.%@@@@@@@@@@@%*+@@@+..*...:.-.==.%@+..                   
                     ..%@*.:-*=#..#..:#..=..-@@@@@@@@=@@@-@@+@@%..#=-+.+#.+@@..                     
                       .:@@*.#..++*-:*..%..*.%@@@@@@-@@%@@@@@@@@@#.-%.%.+@@-.                       
                        ..-%@%:-:%::+-.*.-=:.%@@@@@@@%%@@@#-:........:#@@-.                         
                          ..:#@@*..++=#-%-#.:@@@@@@@@@*-....-..--:.+@@%=...                            
                             ..-#@@#=:-+:*..%@@@@@@%:.....=+=*..*@@%=...                            
                                 .:*%@@%...#@@@@@*....=-.:-+%@@:+:..                                
                                   ...... -@@@@#.. .%@@@@@%#-...                                    
                                        ..%@@%.    .....                                            
                                          ....                                                    
endef
export ART

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

SRC = main.c print.c parsing.c philo.c clean.c array_create.c

OBJ_DIR = obj
OBJ_FILES = $(SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)
	@echo ""
	@echo "$(YELLOW)$$HEADER$(RESET)"
	@echo "$(YELLOW)$$ART$(RESET)"

$(NAME) : $(OBJ_FILES)  $(LIBFT)
	@echo "$(GREEN)making philo...$(RESET)"
	@$(CC) $(OBJ_FILES)  $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "$(GREEN)making libft...$(RESET)"
	@make all -C libft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean: clean
	@echo "$(BLUE)cleaning program...$(RESET)"
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY : all fclean clean re bonus
