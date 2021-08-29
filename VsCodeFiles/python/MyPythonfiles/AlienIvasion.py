# coding=gbk   将编码改为gbk,以便可以使用中文注释等
#######################################################################
#   python实践小项目
#  《外星人入侵》
#   作者:叶栋
#   状态：优化中
#######################################################################
import sys
import pygame
import pygame.font
from pygame.sprite import Group
from pygame.sprite import Sprite
from time import sleep

class Settings:
    """储存游戏《外星人入侵》中所有设置的类"""
    def __init__(self):
        """初始化游戏的静态设置"""
        #屏幕设置
        self.screen_width=1200
        self.screen_height=800
        self.bg_color=(188,92,111)

        #飞船设置
        self.ship_speed = 1.0
        self.ship_limit = 3         #三条命

        #子弹设置
        self.bullet_speed = 1.0
        self.bullet_width = 10
        self.bullet_height = 10
        self.bullet_color = (60, 60, 60)
        self.Alienbullet_color = (120, 120, 120)
        self.bullets_allowed = 30           #允许在屏幕上存在的最大子弹数

        #外星人设置
        self.alien_speed = 1.0
        self.fleet_drop_speed = 10
        #加快游戏节奏速度
        self.speedup_scale = 1.1
        #外星人分数提高的速度
        self.score_scale = 1.5
        self.initialize_dynamic_settings()

    def initialize_dynamic_settings(self):
        """初始化随游戏进行而变化的设置"""
        self.ship_speed = 1.5
        self.bullet_speed = 3.0
        self.alien_speed = 1.0
        #fleet_direction 为1表示向右，为-1表示向左
        self.fleet_direction = 1
        #记分
        self.alien_points = 50

    def increase_speed(self):
        """提高速度设置和外星人分数"""
        self.ship_speed *= self.speedup_scale
        self.bullet_speed *= self.speedup_scale
        self.alien_speed *= self.speedup_scale
        self.alien_points = int(self.alien_points * self.score_scale)
        print(self.alien_points)


class Ship(Sprite):
    """管理飞船的类"""
    def __init__(self, ai_game):            # ai_game为当前AlienIvasion实例的一个引用（作飞船初始化的一个参数，以便ship                                              ）
        """初始化飞船并设置其初始位置"""      #  可以访问整个游戏中的所有资源）
        super().__init__()
        self.screen=ai_game.screen          # 将屏幕赋给了ship的一个属性，以便ship中的所有方法可以轻松访问屏幕
        self.settings = ai_game.settings    # 将settings类赋给ship的一个属性，原因同上
        self.screen_rect=ai_game.screen.get_rect()  #使用方法get_rect访问屏幕属性，以便将飞船放在屏幕合适位置
        #加载飞船图像并获取其外接矩形rect
        self.image=pygame.image.load('D:\myfile\python\Mygame\plane.bmp')   #获取飞船图片
        self.image=pygame.transform.scale(self.image,(120,120))             #缩小获得的飞船图片尺寸
        self.rect=self.image.get_rect()                                     #将飞船图片位置附给ship，在屏幕展示出来即为飞船
        #对于每艘新的飞船，都将其放在屏幕底部的中央
        self.rect.midbottom=self.screen_rect.midbottom
        #在飞船的属性x中存储最小数值
        self.x = float(self.rect.x)
        #移动标志
        self.moving_right = False
        self.moving_left = False

    def update(self):
        """根据移动标志调整飞船位置"""
        #更新飞船而不是rect对象的x值
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.x += self.settings.ship_speed
        if self.moving_left and self.rect.left > 0:
            self.x -= self.settings.ship_speed
        #根据self.x更新rect对象
        self.rect.x = self.x 
    def blitme(self):
        """在指定位置绘制飞船"""
        self.screen.blit(self.image,self.rect)
    def center_ship(self):
        """让飞船在屏幕底端居中"""
        self.rect.midbottom = self.screen_rect.midbottom
        self.x = float(self.rect.x)
class Button:
    def __init__(self, ai_game, msg):
        """初始化按钮的属性"""
        self.screen = ai_game.screen
        self.screen_rect = self.screen.get_rect()

        #设置按钮的尺寸和其他属性
        self.width, self.height = 200, 50
        self.button_color = (0, 255, 0)
        self.text_color = (255, 255, 255)
        self.font = pygame.font.SysFont(None, 48)

        #设置按钮rect对象，并使其居中
        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.center = self.screen_rect.center

        #按钮的标签只需创建一次
        self._prep_msg(msg)

    def _prep_msg(self, msg):
        """将msg渲染为图像，并使其在按钮上居中"""
        self.msg_image = self.font.render(msg, True, self.text_color, self.button_color)
        self.msg_image_rect = self.msg_image.get_rect()
        self.msg_image_rect.center = self.rect.center

    def draw_button(self):
        #绘制一个用颜色填充的按钮， 在绘制文本
        self.screen.fill(self.button_color, self.rect)
        self.screen.blit(self.msg_image, self.msg_image_rect)

class Bullet(Sprite):
    """管理飞船所发射子弹的类"""
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings 
        self.color = self.settings.bullet_color

        #在（0，0）处创建一个表示子弹的矩形，再设置正确的位置
        self.rect = pygame.Rect(0, 0, self.settings.bullet_width,self.settings.bullet_height)
        self.rect.midtop = ai_game.ship.rect.midtop

        #储存用小数表示对子弹的位置
        self.y = float(self.rect.y)

    def update(self):
        """向上移动子弹"""
        # 更新表示子弹位置的小数值
        self.y -=self.settings.bullet_speed
        #更新表示子弹的rect的位置
        self.rect.y = self.y

    def draw_bullet(self):
        """在屏幕上绘制子弹"""
        pygame.draw.rect(self.screen, self.color, self.rect)

class Alien(Sprite):
    """表示单个外星人的类"""
    def __init__(self, ai_game):
        """初始化外星人并设置其初始位置"""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings

        #加载外星人图像并设置其rect属性
        self.image = pygame.image.load("D:\myfile\python\Mygame\Alien.bmp")
        self.image=pygame.transform.scale(self.image,(50,50))    
        self.rect = self.image.get_rect()

        #每个外星人最初都在屏幕左上角附近
        self.rect.x = self.rect.width 
        self.rect.y = self.rect.height 

        #储存外星人的精确水平位置
        self.x = float(self.rect.x)
        #外星人的子弹

    def update(self):
        """向左或向右移动外星人"""
        self.x += (self.settings.alien_speed*self.settings.fleet_direction)
        self.rect.x = self.x

    def check_edges(self):
        """如果外星人位于屏幕边缘，就返回true"""
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right or self.rect.left <= 0:
            return True 
   
class AlienBullet(Sprite):
    """管理外星人所发射的子弹的类"""
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings 
        self.color = self.settings.Alienbullet_color

        self.rect = pygame.Rect(0, 0, self.settings.bullet_width,self.settings.bullet_height)
        self.rect.midtop = ai_game.alien.rect.midtop

    def downdate(self):
        self.y += self.settings.bullet_speed
        self.rect.y = self.y

    def draw_bullet(self):
        pygame.draw.rect(self.screen, self.color, self.rect)

class GameStats:
    """跟踪游戏的统计信息"""
    def __init__(self, ai_game):
        """初始化统计信息"""
        self.settings =ai_game.settings
        self.reset_stats()
        #游戏刚启动时处于活动状态
        self.game_active = False
        #任何情况下都不应重置最高得分
        self.high_score = 0

    def reset_stats(self):
        """初始化在游戏运行期间可能变化的统计信息"""
        self.ships_left = self.settings.ship_limit
        self.score = 0
        self.level = 1

class Scoreboard:
    """显示得分信息的类"""
    def __init__(self, ai_game):
        """初始化显示得分涉及的属性"""
        self.ai_game = ai_game
        self.screen = ai_game.screen
        self.screen_rect = self.screen.get_rect()
        self.settings = ai_game.settings
        self.stats = ai_game.stats
        #显示得分信息时使用的字体设置
        self.text_color = (30,30,30)
        self.font = pygame.font.SysFont(None, 48)
        #准备初始最高得分和当前得分图像
        self.prep_score()
        self.prep_high_score()
        self.prep_level()
        self.prep_ships()

    def prep_ships(self):
        """显示还余下多少艘飞船"""
        self.ships = Group()
        for ship_number in range(self.stats.ships_left):
            ship = Ship(self.ai_game)
            ship.rect.x = 10 + ship_number *ship.rect.width
            ship.rect.y = 10
            self.ships.add(ship)

    def prep_level(self):
        """将等级转换为渲染的图像"""
        level_str = str(self.stats.level)
        self.level_image = self.font.render(level_str, True, self.text_color, self.settings.bg_color)
        #将等级放在得分下方
        self.level_rect = self.level_image.get_rect()
        self.level_rect.right = self.score_rect.right
        self.level_rect.top = self.score_rect.bottom + 10
    
    def prep_high_score(self):
        """将最高得分转换为渲染的图像"""
        high_score = round(self.stats.high_score, -1)
        high_score_str = "{:,}".format(high_score)
        self.high_score_image = self.font.render(high_score_str, True, self.text_color, self.settings.bg_color)
        #将最高得分放在屏幕顶部中央
        self.high_score_rect = self.high_score_image.get_rect()
        self.high_score_rect.centerx = self.screen_rect.centerx
        self.high_score_rect.top = self.score_rect.top

    def prep_score(self):
        """将得分转化为一幅渲染的图像"""
        rounded_score = round(self.stats.score, -1)
        score_str = "{:,}".format(rounded_score)
        self.score_image = self.font.render(score_str, True, self.text_color, self.settings.bg_color)
        #在屏幕右上角显示得分
        self.score_rect = self.score_image.get_rect()
        self.score_rect.right = self.screen_rect.right - 20
        self.score_rect.top = 20
    
    def check_high_score(self):
        """检查是否产生了新的最高得分"""
        if self.stats.score > self.stats.high_score:
            self.stats.high_score = self.stats.score
            self.prep_high_score()
    
    def show_score(self):
        """在屏幕上显示得分和等级和余下的飞船数"""
        self.screen.blit(self.score_image, self.score_rect)
        self.screen.blit(self.high_score_image, self.high_score_rect)
        self.screen.blit(self.level_image, self.level_rect)
        self.ships.draw(self.screen)

class AlienIvasion:
    """管理游戏资源和行为的类"""
    def __init__(self):
        """初始化游戏并创建游戏资源"""
        pygame.init()
        self.settings=Settings()
        self.screen = pygame.display.set_mode((0, 0),pygame.FULLSCREEN)
        self.settings.screen_width = self.screen.get_rect().width
        self.settings.sceen_height = self.screen.get_rect().height
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        #创建一个用于储存游戏统计信息的实例
        #并创建记分牌
        self.stats = GameStats(self)
        self.sb = Scoreboard(self)
        #创建一个飞船实列
        self.ship=Ship(self)
        #创建子弹实例
        self.bullets = pygame.sprite.Group()
        #创建外星人实例
        self.aliens = pygame.sprite.Group()
        self.alien = Alien(self)
        self._create_fleet()
        #创建play按钮
        self.play_button = Button(self, "Play")

    def _ship_hit(self):
        """响应飞船被外星人撞到"""
        if self.stats.ships_left > 0:
            #将ships_left减1并更新记分牌
            self.stats.ships_left -= 1
            self.sb.prep_ships()
            #清空余下的外星人和子弹
            self.aliens.empty()
            self.bullets.empty()
            #创建一群新的外星人，并将飞船放到屏幕底端的中央
            self._create_fleet()
            self.ship.center_ship()
             #暂停
            sleep(0.5)
        else:
            self.stats.game_active = False

    def _check_aliens_bottom(self):
        """检查是否有外星人到达了屏幕底端"""
        screen_rect = self.screen.get_rect()
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                #像飞船被撞到一样处理
                self._ship_hit()
                break

    def _check_fleet_edges(self):
        """有外星人到达屏幕边缘时即采取相应措施"""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    def _change_fleet_direction(self):
        """将整群外星人下移并改变他们的方向"""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= -1

    def _create_alien(self,alien_number, row_number):
         #创建一个外星人并将其加入当前行
        alien =Alien(self)
        alien_width, alien_height = alien.rect.size 
        alien_width = alien.rect.width
        alien.x = alien_width + 2*alien_width*alien_number
        alien.rect.x = alien.x
        alien.rect.y = alien.rect.height + 2*alien.rect.height*row_number
        self.aliens.add(alien)

    def _create_fleet(self):
        """创建外星人群"""
        #创建一个外星人并计算一行可以容纳多少外星人
        #外星人的间距为外星人的宽度
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size 
        available_space_x = self.settings.screen_width - (2*alien_width)
        number_aliens_x = available_space_x // (2*alien_width)
        #计算屏幕可以容纳多少外星人
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height - (3*alien_height) - ship_height)
        number_rows = available_space_y // (2*alien_height)
        #创建外星人人群
        for row_number in range(number_rows):
            for alien_number in range(number_aliens_x):
                self._create_alien(alien_number, row_number)

    def _fire_bullet(self):
        """创建一颗子弹，将其加入编组bullets中"""
        if len(self.bullets) < self.settings.bullets_allowed:
            new_bullet = Bullet(self)
            self.bullets.add(new_bullet)

    def _update_bullets(self):
        """更新子弹的位置并删除消失的子弹"""
        #更新子弹的位置
        self.bullets.update()
        #删除消失的子弹
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <= 0:
                self.bullets.remove(bullet)
        self._check_bullet_alien_collisions()

    def _check_bullet_alien_collisions(self):
        #检查是否有子弹击中了外星人
        #如果是，就删除相应的子弹和外星人
        collisions = pygame.sprite.groupcollide(self.bullets, self.aliens, True, True)
        if collisions :
            for aliens in collisions.values():
                self.stats.score += self.settings.alien_points * len(aliens)
                self.sb.prep_score()
                self.sb.check_high_score()
        if not self.aliens:
            #删除现有的子弹并新创建一群外星人
            self.bullets.empty()
            self._create_fleet()
            self.settings.increase_speed()
            #提高等级
            self.stats.level += 1
            self.sb.prep_level()

    def _check_keydown_events(self,event):
        """响应按键"""
        if event.key == pygame.K_RIGHT:
             #向右移动飞船
            self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = True
        elif event.key ==pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_SPACE:
            self._fire_bullet()

    def _check_keyup_events(self,event):
        """响应松开"""
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False

    def _check_events(self):
        """响应按键和鼠标事件"""
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                    self._check_keyup_events(event)
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                self._check_play_button(mouse_pos)

    def _check_play_button(self, mouse_pos):
        """在玩家点击Play按钮时开始新游戏"""
        button_clicked = self.play_button.rect.collidepoint(mouse_pos)

        if button_clicked and not self.stats.game_active:
            """重置游戏统计信息"""
            self.settings.initialize_dynamic_settings()
            self.stats.reset_stats()
            self.stats.game_active = True
            self.sb.prep_score()
            self.sb.prep_level()
            self.sb.prep_ships()
            #清空余下的外星人和子弹
            self.aliens.empty()
            self.bullets.empty()
            #创建一群新的外星人并让飞船居中
            self._create_fleet()
            self.ship.center_ship()

    def _update_screen(self):
        """更新屏幕上的图像，并切换到新屏幕"""
        self.screen.fill(self.settings.bg_color)
        self.ship.blitme()
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
        self.aliens.draw(self.screen)
        #显示得分
        self.sb.show_score()
        #如果游戏处于非活动状态，就绘制Play按钮
        if not self.stats.game_active:
            self.play_button.draw_button()
        #让最近绘制的屏幕可见
        pygame.display.flip()

    def _update_aliens(self):
        """"
        检查是否有外星人位于屏幕边缘
        并更新整群外星人的位置
        """
        self._check_fleet_edges()
        self.aliens.update()
        #检测外星人和飞船之间的碰撞
        if pygame.sprite.spritecollideany(self.ship, self.aliens):
            self._ship_hit()
        #检查是否有外星人到达了屏幕底端
        self._check_aliens_bottom()

    def run_game(self):
        """开始游戏的主循环"""
        while True:
            self._check_events()
            if self.stats.game_active:
                self.ship.update()
                self._update_bullets()
                self._update_aliens()
            self._update_screen()   

if  __name__=='__main__':
    #创建游戏实例并运行游戏
    ai = AlienIvasion()
    ai.run_game()

# 所学收获：AlienIvasion是一个大类（相当于此游戏），而如ship，settings, Buttled等相当于这个大类的一部分，但他们与AlienIvasion又不是包含关系
# 倒是像身体和四肢，头之间的关系一样. 他们之间也存在着各种关系
# 进行一个项目，就像搭建房子一样，得先有一个基本的框架


