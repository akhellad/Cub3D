MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

all:
	@$(MAKE) -C $(MANDATORY_DIR)

bonus:
	@$(MAKE) -C $(BONUS_DIR)

clean:
	@$(MAKE) clean -C $(MANDATORY_DIR)
	@$(MAKE) clean -C $(BONUS_DIR)

fclean:
	@$(MAKE) fclean -C $(MANDATORY_DIR)
	@$(MAKE) fclean -C $(BONUS_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
